// Copyright 2014 BVLC and contributors.

#include <opencv2/opencv.hpp>
#include <string>

#include "caffe/common.hpp"
#include "caffe/util/format.hpp"

#include "caffe/proto/caffe.pb.h"

namespace caffe {
using std::string;

bool OpenCVImageToDatum(
    const cv::Mat& image, const int label, const int height,
    const int width, Datum* datum, const bool is_color) {
  cv::Mat cv_img;
  CHECK(image.data) << "Image data must not be NULL";
  CHECK_GT(image.rows, 0) << "Image height must be positive";
  CHECK_GT(image.cols, 0) << "Image width must be positive";
  if (height > 0 && width > 0 &&
      (image.rows != height || image.cols != width)) {
    cv::resize(image, cv_img, cv::Size(width, height));
  } else {
    cv_img = image;
  }
  int num_channels = (is_color ? 3 : 1);
  datum->set_channels(num_channels);
  datum->set_height(cv_img.rows);
  datum->set_width(cv_img.cols);
  datum->set_label(label);
  datum->clear_data();
  datum->clear_float_data();
  string* datum_string = datum->mutable_data();
  if (is_color) {
    for (int c = 0; c < num_channels; ++c) {
      for (int h = 0; h < cv_img.rows; ++h) {
        for (int w = 0; w < cv_img.cols; ++w) {
          datum_string->push_back(
            static_cast<char>(cv_img.at<cv::Vec3b>(h, w)[c]));
        }
      }
    }
  } else {  // Faster than repeatedly testing is_color for each pixel w/i loop
    for (int h = 0; h < cv_img.rows; ++h) {
      for (int w = 0; w < cv_img.cols; ++w) {
        datum_string->push_back(
          static_cast<char>(cv_img.at<uchar>(h, w)));
        }
      }
  }
  return true;
}

template <typename Dtype>
bool OpenCVImageToBlob(
    const cv::Mat& image, const int label, const int height,
    const int width, Blob<Dtype>* blob, const bool is_color) {
  cv::Mat cv_img;
  CHECK(image.data) << "Image data must not be NULL";
  CHECK_GT(image.rows, 0) << "Image height must be positive";
  CHECK_GT(image.cols, 0) << "Image width must be positive";
  if (height > 0 && width > 0 &&
      (image.rows != height || image.cols != width)) {
    cv::resize(image, cv_img, cv::Size(width, height));
  } else {
    cv_img = image;
  }
  const int num_channels = is_color ? 3 : 1;
  blob->Reshape(1, num_channels, cv_img.rows, cv_img.cols);
  Dtype* data = blob->mutable_cpu_data();
  if (is_color) {
    for (int c = 0; c < num_channels; ++c) {
      for (int h = 0; h < cv_img.rows; ++h) {
        for (int w = 0; w < cv_img.cols; ++w) {
          data[blob->offset(0, c, h, w)] =
            static_cast<Dtype>(cv_img.at<cv::Vec3b>(h, w)[c]);
        }
      }
    }
  } else {  // Faster than repeatedly testing is_color for each pixel w/i loop
    for (int h = 0; h < cv_img.rows; ++h) {
      for (int w = 0; w < cv_img.cols; ++w) {
        data[blob->offset(0, 0, h, w)] =
          static_cast<Dtype>(cv_img.at<uchar>(h, w));
        }
      }
  }
  return true;
}

template
bool OpenCVImageToBlob<float>(
    const cv::Mat& image, const int label, const int height,
    const int width, Blob<float>* blob, const bool is_color);
template
bool OpenCVImageToBlob<double>(
    const cv::Mat& image, const int label, const int height,
    const int width, Blob<double>* blob, const bool is_color);

}  // namespace caffe
