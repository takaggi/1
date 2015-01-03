#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

#include "caffe/layer.hpp"
#include "caffe/util/io.hpp"
#include "caffe/util/math_functions.hpp"
#include "caffe/vision_layers.hpp"

namespace caffe {

template <typename Dtype>
void AccuracyLayer<Dtype>::LayerSetUp(
  const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) {
  top_k_ = this->layer_param_.accuracy_param().top_k();
  output_per_class_ = this->layer_param_.accuracy_param().output_per_class();
}

template <typename Dtype>
void AccuracyLayer<Dtype>::Reshape(
  const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) {
  CHECK_EQ(bottom[0]->num(), bottom[1]->num())
      << "The data and label should have the same number.";
  CHECK_LE(top_k_, bottom[0]->count() / bottom[0]->num())
      << "top_k must be less than or equal to the number of classes.";
  CHECK_EQ(bottom[1]->channels(), 1);
  CHECK_EQ(bottom[1]->height(), 1);
  CHECK_EQ(bottom[1]->width(), 1);
  int dim = 0;
  if (output_per_class_) {
    dim += bottom[0]->count() / bottom[0]->num();
  }
  top[0]->Reshape(1 + dim, 1, 1, 1);
}

template <typename Dtype>
void AccuracyLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top) {
  Dtype accuracy = 0;
  const Dtype* bottom_data = bottom[0]->cpu_data();
  const Dtype* bottom_label = bottom[1]->cpu_data();
  int num = bottom[0]->num();
  int dim = bottom[0]->count() / bottom[0]->num();
  vector<Dtype> maxval(top_k_+1);
  vector<int> max_id(top_k_+1);
  vector<Dtype> accuracies(dim, 0);
  vector<Dtype> nums(dim, 0);
  for (int i = 0; i < num; ++i) {
    const int true_label = static_cast<int>(bottom_label[i]);
    // Top-k accuracy
    std::vector<std::pair<Dtype, int> > bottom_data_vector;
    for (int j = 0; j < dim; ++j) {
      bottom_data_vector.push_back(
          std::make_pair(bottom_data[i * dim + j], j));
    }
    std::partial_sort(
        bottom_data_vector.begin(), bottom_data_vector.begin() + top_k_,
        bottom_data_vector.end(), std::greater<std::pair<Dtype, int> >());
    // check if true label is in top k predictions
    for (int k = 0; k < top_k_; k++) {
      ++nums[true_label];
      if (bottom_data_vector[k].second == true_label) {
        ++accuracy;
        ++accuracies[true_label];
        break;
      }
    }
  }

  // LOG(INFO) << "Accuracy: " << accuracy;
  top[0]->mutable_cpu_data()[0] = accuracy / num;
  if (output_per_class_) {
    for (int i = 0; i < dim; ++i) {
      top[0]->mutable_cpu_data()[i + 1] = accuracies[i] / nums[i];
    }
  }
  // Accuracy layer should not be used as a loss function.
}

INSTANTIATE_CLASS(AccuracyLayer);
REGISTER_LAYER_CLASS(ACCURACY, AccuracyLayer);
}  // namespace caffe
