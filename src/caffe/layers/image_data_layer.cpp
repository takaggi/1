#include <opencv2/core/core.hpp>

#include <fstream>  // NOLINT(readability/streams)
#include <iostream>  // NOLINT(readability/streams)
#include <string>
#include <utility>
#include <vector>

#include "caffe/data_layers.hpp"
#include "caffe/layer.hpp"
#include "caffe/util/benchmark.hpp"
#include "caffe/util/io.hpp"
#include "caffe/util/math_functions.hpp"
#include "caffe/util/rng.hpp"

namespace caffe {


template <typename Dtype>
int ImageDataLayer<Dtype>::findNumOccurrences(char delim, std::string text) {
  int count = 0;
  int pos = text.find(delim, 0);
  while(pos != text.npos) {
    pos = text.find(delim, pos+1);
    count++;
  }
  return count;
}

template <typename Dtype>
void ImageDataLayer<Dtype>::split(char delim, std::string &line, std::vector<std::string> &parts) {
  int pos = line.find(delim, 0);
  int last_pos = 0;
  while(pos != line.npos) {
    parts.push_back(line.substr(last_pos, pos - last_pos));
    last_pos = pos+1;
    pos = line.find(delim, pos+1);
  }
  parts.push_back(line.substr(last_pos, line.size()-1));
}

template <typename Dtype>
ImageDataLayer<Dtype>::~ImageDataLayer<Dtype>() {
  this->JoinPrefetchThread();
}

template <typename Dtype>
void ImageDataLayer<Dtype>::DataLayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  const int new_height = this->layer_param_.image_data_param().new_height();
  const int new_width  = this->layer_param_.image_data_param().new_width();
  const bool is_color  = this->layer_param_.image_data_param().is_color();
  const int batch_size = this->layer_param_.image_data_param().batch_size();
  string root_folder = this->layer_param_.image_data_param().root_folder();

  CHECK((new_height == 0 && new_width == 0) ||
      (new_height > 0 && new_width > 0)) << "Current implementation requires "
      "new_height and new_width to be set at the same time.";
  // Read the file with filenames and labels
  const string& source = this->layer_param_.image_data_param().source();
  LOG(INFO) << "Opening file " << source;
  std::ifstream infile(source.c_str());
  std::string line;
  char delimiter = 0;
  std::vector<std::string> filenames;
  int label;

  // read one line and find the delimiter
  CHECK(std::getline(infile, line)) << "Failed to read from input file."
      "";
  // find delimiter occurrences
  // 2 occurrences means it can be slit in 2 files and a label
  if(findNumOccurrences(' ', line) == this->input_data_size_) {
    delimiter = ' ';
  } else
  if(findNumOccurrences(',', line) == this->input_data_size_) {
    delimiter = ',';
  } else
  if(findNumOccurrences('\t', line) == this->input_data_size_) {
    delimiter = '\t';
  }
  CHECK(delimiter != 0) << "Input size for data layer doesn't match the text file.";

  do {
    std::vector<std::string> filenames;
    split(delimiter, line, filenames);
    label = std::atoi(filenames.back().c_str());
    filenames.pop_back();
    lines_.push_back(std::make_pair(filenames, label));
  } while (std::getline(infile, line));

  if (this->layer_param_.image_data_param().shuffle()) {
    // randomly shuffle data
    LOG(INFO) << "Shuffling data";
    const unsigned int prefetch_rng_seed = caffe_rng_rand();
    prefetch_rng_.reset(new Caffe::RNG(prefetch_rng_seed));
    ShuffleImages();
  }
  LOG(INFO) << "A total of " << lines_.size() << " images.";

  lines_id_ = 0;
  // Check if we would need to randomly skip a few data points
  if (this->layer_param_.image_data_param().rand_skip()) {
    unsigned int skip = caffe_rng_rand() %
        this->layer_param_.image_data_param().rand_skip();
    LOG(INFO) << "Skipping first " << skip << " data points.";
    CHECK_GT(lines_.size(), skip) << "Not enough points to skip";
    lines_id_ = skip;
  }
  for(int img_counter = 0; img_counter < this->input_data_size_; img_counter++) {
    // Read an image, and use it to initialize the top blob.
    cv::Mat cv_img = ReadImageToCVMat(root_folder + lines_[lines_id_].first.at(img_counter),
                                      new_height, new_width, is_color);
    // Use data_transformer to infer the expected blob shape from a cv_image.
    vector<int> top_shape = this->data_transformer_->InferBlobShape(cv_img);
    this->transformed_data_.Reshape(top_shape);
    // Reshape prefetch_data and top[0] according to the batch_size.
    top_shape[0] = batch_size;
    this->prefetch_data_[img_counter]->Reshape(top_shape);
    top[img_counter]->ReshapeLike(*(this->prefetch_data_[img_counter]));

    LOG(INFO) << "output data size: " << top[img_counter]->num() << ","
        << top[img_counter]->channels() << "," << top[img_counter]->height() << ","
        << top[img_counter]->width();

  }
  // label
  vector<int> label_shape(1, batch_size);
  top.back()->Reshape(label_shape);
  this->prefetch_label_.Reshape(label_shape);
}

template <typename Dtype>
void ImageDataLayer<Dtype>::ShuffleImages() {
  caffe::rng_t* prefetch_rng =
      static_cast<caffe::rng_t*>(prefetch_rng_->generator());
  shuffle(lines_.begin(), lines_.end(), prefetch_rng);
}

// This function is used to create a thread that prefetches the data.
template <typename Dtype>
void ImageDataLayer<Dtype>::InternalThreadEntry() {
  CPUTimer batch_timer;
  batch_timer.Start();
  double read_time = 0;
  double trans_time = 0;
  CPUTimer timer;
  CHECK(this->prefetch_data_[0]->count());
  CHECK(this->transformed_data_.count());
  ImageDataParameter image_data_param = this->layer_param_.image_data_param();
  const int batch_size = image_data_param.batch_size();
  const int new_height = image_data_param.new_height();
  const int new_width = image_data_param.new_width();
  const bool is_color = image_data_param.is_color();
  string root_folder = image_data_param.root_folder();

  // Reshape according to the first image of each batch
  // on single input batches allows for inputs of varying dimension.
  cv::Mat cv_img = ReadImageToCVMat(root_folder + lines_[lines_id_].first.at(0),
      new_height, new_width, is_color);
  // Use data_transformer to infer the expected blob shape from a cv_img.
  vector<int> top_shape = this->data_transformer_->InferBlobShape(cv_img);
  this->transformed_data_.Reshape(top_shape);
  // Reshape prefetch_data according to the batch_size.
  top_shape[0] = batch_size;
  for(int img_counter = 0; img_counter < this->input_data_size_; img_counter++) {
    this->prefetch_data_[img_counter]->Reshape(top_shape);
  }

  std::vector<Dtype*> prefetch_data;
  for(int img_counter = 0; img_counter < this->input_data_size_; img_counter++) {
    prefetch_data.push_back(this->prefetch_data_[img_counter]->mutable_cpu_data());
  }
  Dtype* prefetch_label = this->prefetch_label_.mutable_cpu_data();
  // datum scales
  const int lines_size = lines_.size();
  for (int item_id = 0; item_id < batch_size; ++item_id) {
    for(int img_counter = 0; img_counter < this->input_data_size_; img_counter++) {
      // get a blob
      timer.Start();
      CHECK_GT(lines_size, lines_id_);
      cv::Mat cv_img = ReadImageToCVMat(root_folder + lines_[lines_id_].first.at(img_counter),
          new_height, new_width, is_color);
      CHECK(cv_img.data) << "Could not load " << lines_[lines_id_].first.at(img_counter);
      read_time += timer.MicroSeconds();
      timer.Start();
      // Apply transformations (mirror, crop...) to the image
      int offset = this->prefetch_data_[img_counter]->offset(item_id);
      this->transformed_data_.set_cpu_data(prefetch_data[img_counter] + offset);
      this->data_transformer_->Transform(cv_img, &(this->transformed_data_));
      trans_time += timer.MicroSeconds();
    }

    prefetch_label[item_id] = lines_[lines_id_].second;

    // go to the next iter
    lines_id_++;
    if (lines_id_ >= lines_size) {
      // We have reached the end. Restart from the first.
      DLOG(INFO) << "Restarting data prefetching from start.";
      lines_id_ = 0;
      if (this->layer_param_.image_data_param().shuffle()) {
        ShuffleImages();
      }
    }
  }
  batch_timer.Stop();

  DLOG(INFO) << "Prefetch batch: " << batch_timer.MilliSeconds() << " ms.";
  DLOG(INFO) << "     Read time: " << read_time / 1000 << " ms.";
  DLOG(INFO) << "Transform time: " << trans_time / 1000 << " ms.";
}

INSTANTIATE_CLASS(ImageDataLayer);
REGISTER_LAYER_CLASS(ImageData);

}  // namespace caffe
