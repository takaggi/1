#include <algorithm>
#include <vector>

<<<<<<< HEAD
<<<<<<< HEAD
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
=======
#include "caffe/device.hpp"
#include "caffe/layer.hpp"
#include "caffe/vision_layers.hpp"
>>>>>>> BVLC/device-abstraction
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#include "caffe/device.hpp"
#include "caffe/layer.hpp"
#include "caffe/vision_layers.hpp"
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> BVLC/master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> BVLC/master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> BVLC/master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> caffe
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> BVLC/master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> master
=======
#include "caffe/common_layers.hpp"
#include "caffe/util/math_functions.hpp"
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge

namespace caffe {

template <typename Dtype>
void SoftmaxLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  softmax_axis_ =
      bottom[0]->CanonicalAxisIndex(this->layer_param_.softmax_param().axis());
  top[0]->ReshapeLike(*bottom[0]);
  vector<int> mult_dims(1, bottom[0]->shape(softmax_axis_));
  sum_multiplier_.Reshape(mult_dims);
<<<<<<< HEAD
  Dtype* multiplier_data = sum_multiplier_.mutable_cpu_data();
=======
<<<<<<< HEAD
  Dtype* multiplier_data = sum_multiplier_.mutable_cpu_data();
  caffe_set(sum_multiplier_.count(), Dtype(1), multiplier_data);
  outer_num_ = bottom[0]->count(0, softmax_axis_);
  inner_num_ = bottom[0]->count(softmax_axis_ + 1);
  vector<int> scale_dims = bottom[0]->shape();
  scale_dims[softmax_axis_] = 1;
  scale_.Reshape(scale_dims);
=======
  top[0]->Reshape(bottom[0]->num(), bottom[0]->channels(),
      bottom[0]->height(), bottom[0]->width());
  sum_multiplier_.Reshape(1, bottom[0]->channels(), 1, 1);
  Dtype* multiplier_data = sum_multiplier_.mutable_cpu_data();
  for (int i = 0; i < sum_multiplier_.count(); ++i) {
    multiplier_data[i] = 1.;
  }
  scale_.Reshape(bottom[0]->num(), 1, bottom[0]->height(), bottom[0]->width());
>>>>>>> origin/BVLC/parallel
=======
  Dtype* multiplier_data = sum_multiplier_.mutable_cpu_data();
>>>>>>> pod-caffe-pod.hpp-merge
  caffe_set(sum_multiplier_.count(), Dtype(1), multiplier_data);
  outer_num_ = bottom[0]->count(0, softmax_axis_);
  inner_num_ = bottom[0]->count(softmax_axis_ + 1);
  vector<int> scale_dims = bottom[0]->shape();
  scale_dims[softmax_axis_] = 1;
  scale_.Reshape(scale_dims);
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}

template <typename Dtype>
void SoftmaxLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top) {
  const Dtype* bottom_data = bottom[0]->cpu_data();
  Dtype* top_data = top[0]->mutable_cpu_data();
  Dtype* scale_data = scale_.mutable_cpu_data();
<<<<<<< HEAD
<<<<<<< HEAD
  int channels = bottom[0]->shape(softmax_axis_);
  int dim = bottom[0]->count() / outer_num_;
  caffe_copy(bottom[0]->count(), bottom_data, top_data);
  // We need to subtract the max to avoid numerical issues, compute the exp,
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  int num = bottom[0]->num();
  int channels = bottom[0]->channels();
  int dim = bottom[0]->count() / bottom[0]->num();
<<<<<<< HEAD
  GetDevice<Dtype>(Caffe::CPU)->copy(bottom[0]->count(), bottom_data, top_data);
  // we need to subtract the max to avoid numerical issues, compute the exp,
>>>>>>> BVLC/device-abstraction
=======
<<<<<<< HEAD
  GetDevice<Dtype>(Caffe::CPU)->copy(bottom[0]->count(), bottom_data, top_data);
  // we need to subtract the max to avoid numerical issues, compute the exp,
=======
=======
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> caffe
  int channels = bottom[0]->shape(softmax_axis_);
  int dim = bottom[0]->count() / outer_num_;
  caffe_copy(bottom[0]->count(), bottom_data, top_data);
  // We need to subtract the max to avoid numerical issues, compute the exp,
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  // and then normalize.
  for (int i = 0; i < outer_num_; ++i) {
    // initialize scale_data to the first plane
    caffe_copy(inner_num_, bottom_data + i * dim, scale_data);
    for (int j = 0; j < channels; j++) {
      for (int k = 0; k < inner_num_; k++) {
        scale_data[k] = std::max(scale_data[k],
            bottom_data[i * dim + j * inner_num_ + k]);
      }
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_,
        1, -1., sum_multiplier_.cpu_data(), scale_data, 1., top_data);
    // exponentiation
    caffe_exp<Dtype>(dim, top_data, top_data);
    // sum after exp
    caffe_cpu_gemv<Dtype>(CblasTrans, channels, inner_num_, 1.,
        top_data, sum_multiplier_.cpu_data(), 0., scale_data);
    // division
    for (int j = 0; j < channels; j++) {
      caffe_div(inner_num_, top_data, scale_data, top_data);
      top_data += inner_num_;
    }
  }
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  // subtraction
  GetDevice<Dtype>(Caffe::CPU)->gemm(CblasNoTrans, CblasNoTrans, num, dim, 1,
                                     -1., scale_data,
                                     sum_multiplier_.cpu_data(), 1., top_data);
  // Perform exponentiation
  GetDevice<Dtype>(Caffe::CPU)->exp(num * dim, top_data, top_data);
  // sum after exp
  GetDevice<Dtype>(Caffe::CPU)->gemv(CblasNoTrans, num, dim, 1., top_data,
                                     sum_multiplier_.cpu_data(), 0.,
                                     scale_data);
  // Do division
  for (int i = 0; i < num; ++i) {
    GetDevice<Dtype>(Caffe::CPU)->scal(dim, Dtype(1.) / scale_data[i],
                                       top_data + i * dim);
  }
  return Dtype(0);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
=======
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> master
=======
  int spatial_dim = bottom[0]->height() * bottom[0]->width();
  caffe_copy(bottom[0]->count(), bottom_data, top_data);
  // We need to subtract the max to avoid numerical issues, compute the exp,
  // and then normalize.
  for (int i = 0; i < num; ++i) {
    // initialize scale_data to the first plane
    caffe_copy(spatial_dim, bottom_data + i * dim, scale_data);
    for (int j = 0; j < channels; j++) {
      for (int k = 0; k < spatial_dim; k++) {
        scale_data[k] = std::max(scale_data[k],
            bottom_data[i * dim + j * spatial_dim + k]);
      }
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, spatial_dim,
        1, -1., sum_multiplier_.cpu_data(), scale_data, 1., top_data + i * dim);
    // exponentiation
    caffe_exp<Dtype>(dim, top_data + i * dim, top_data + i * dim);
    // sum after exp
    caffe_cpu_gemv<Dtype>(CblasTrans, channels, spatial_dim, 1.,
        top_data + i * dim, sum_multiplier_.cpu_data(), 0., scale_data);
    // division
    for (int j = 0; j < channels; j++) {
      caffe_div(spatial_dim, top_data + top[0]->offset(i, j), scale_data,
          top_data + top[0]->offset(i, j));
    }
  }
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}

template <typename Dtype>
void SoftmaxLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down,
    const vector<Blob<Dtype>*>& bottom) {
  const Dtype* top_diff = top[0]->cpu_diff();
  const Dtype* top_data = top[0]->cpu_data();
  Dtype* bottom_diff = bottom[0]->mutable_cpu_diff();
  Dtype* scale_data = scale_.mutable_cpu_data();
<<<<<<< HEAD
<<<<<<< HEAD
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  int num = top[0]->num();
  int channels = top[0]->channels();
  int dim = top[0]->count() / top[0]->num();
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  GetDevice<Dtype>(Caffe::CPU)->copy(top[0]->count(), top_diff, bottom_diff);
  // Compute inner1d(top_diff, top_data) and subtract them from the bottom diff
  for (int i = 0; i < num; ++i) {
    GetDevice<Dtype>(Caffe::CPU)->dot(dim, top_diff + i * dim,
                                      top_data + i * dim, scale_data + i);
  }
  // subtraction
  GetDevice<Dtype>(Caffe::CPU)->gemm(CblasNoTrans, CblasNoTrans, num, dim, 1,
                                     -1., scale_data,
                                     sum_multiplier_.cpu_data(), 1.,
                                     bottom_diff);
<<<<<<< HEAD
  // elementwise multiplication
  GetDevice<Dtype>(Caffe::CPU)->mul(top[0]->count(), bottom_diff, top_data,
                                    bottom_diff);
>>>>>>> BVLC/device-abstraction
=======
  // elementwise multiplication
  GetDevice<Dtype>(Caffe::CPU)->mul(top[0]->count(), bottom_diff, top_data,
                                    bottom_diff);
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> BVLC/master
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> BVLC/master
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> BVLC/master
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> master
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> caffe
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> master
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> master
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> BVLC/master
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> master
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> master
=======
  int spatial_dim = top[0]->height() * top[0]->width();
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < num; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < spatial_dim; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, spatial_dim,
          top_data + i * dim + k, spatial_dim);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, spatial_dim, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> origin/BVLC/parallel
=======
  int channels = top[0]->shape(softmax_axis_);
  int dim = top[0]->count() / outer_num_;
  caffe_copy(top[0]->count(), top_diff, bottom_diff);
  for (int i = 0; i < outer_num_; ++i) {
    // compute dot(top_diff, top_data) and subtract them from the bottom diff
    for (int k = 0; k < inner_num_; ++k) {
      scale_data[k] = caffe_cpu_strided_dot<Dtype>(channels,
          bottom_diff + i * dim + k, inner_num_,
          top_data + i * dim + k, inner_num_);
    }
    // subtraction
    caffe_cpu_gemm<Dtype>(CblasNoTrans, CblasNoTrans, channels, inner_num_, 1,
        -1., sum_multiplier_.cpu_data(), scale_data, 1., bottom_diff + i * dim);
  }
  // elementwise multiplication
  caffe_mul(top[0]->count(), bottom_diff, top_data, bottom_diff);
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}


#ifdef CPU_ONLY
STUB_GPU(SoftmaxLayer);
#endif

INSTANTIATE_CLASS(SoftmaxLayer);
<<<<<<< HEAD

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}  // namespace caffe
