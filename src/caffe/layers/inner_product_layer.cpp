// Copyright 2014 BVLC and contributors.

#include <vector>

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/filler.hpp"
#include "caffe/layer.hpp"
#include "caffe/vision_layers.hpp"
#include "caffe/util/math_functions.hpp"

namespace caffe {

template <typename Dtype>
void InnerProductLayer<Dtype>::SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top) {
  Layer<Dtype>::SetUp(bottom, top);
  const int num_output = this->layer_param_.inner_product_param().num_output();
  bias_term_ = this->layer_param_.inner_product_param().bias_term();
  // Figure out the dimensions
  M_ = bottom[0]->num();
  K_ = bottom[0]->count() / bottom[0]->num();
  N_ = num_output;
  (*top)[0]->Reshape(bottom[0]->num(), num_output, 1, 1);
  // Check if we need to set up the weights
  if (this->blobs_.size() > 0) {
    LOG(INFO) << "Skipping parameter initialization";
  } else {
    if (bias_term_) {
      this->blobs_.resize(2);
    } else {
      this->blobs_.resize(1);
    }
    // Intialize the weight
    this->blobs_[0].reset(new Blob<Dtype>(1, 1, N_, K_));
    // fill the weights
    shared_ptr<Filler<Dtype> > weight_filler(GetFiller<Dtype>(
        this->layer_param_.inner_product_param().weight_filler()));
    weight_filler->Fill(this->blobs_[0].get());
    // If necessary, intiialize and fill the bias term
    if (bias_term_) {
      this->blobs_[1].reset(new Blob<Dtype>(1, 1, 1, N_));
      shared_ptr<Filler<Dtype> > bias_filler(GetFiller<Dtype>(
          this->layer_param_.inner_product_param().bias_filler()));
      bias_filler->Fill(this->blobs_[1].get());
    }
  }  // parameter initialization
  // Setting up the bias multiplier
  if (bias_term_) {
    bias_multiplier_.reset(new SyncedMemory(M_ * sizeof(Dtype)));
    Dtype* bias_multiplier_data =
        reinterpret_cast<Dtype*>(bias_multiplier_->mutable_data());
    for (int i = 0; i < M_; ++i) {
        bias_multiplier_data[i] = 1.;
    }
  }
}

template <typename Dtype>
Dtype InnerProductLayer<Dtype>::Forward(const vector<Blob<Dtype>*>& bottom,
    vector<Blob<Dtype>*>* top) {
  const Dtype* bottom_data = bottom[0]->const_data();
  Dtype* top_data = (*top)[0]->mutable_data();
  const Dtype* weight = this->blobs_[0]->const_data();
  DeviceFactory<Dtype>::GetDevice()->gemm(
      CblasNoTrans, CblasTrans, M_, N_, K_, (Dtype)1.,
      bottom_data, weight, (Dtype)0., top_data);
  if (bias_term_) {
    DeviceFactory<Dtype>::GetDevice()->gemm(
        CblasNoTrans, CblasNoTrans, M_, N_, 1, (Dtype)1.,
        reinterpret_cast<const Dtype*>(bias_multiplier_->const_data()),
        this->blobs_[1]->const_data(), (Dtype)1., top_data);
  }
  return Dtype(0);
}

template <typename Dtype>
void InnerProductLayer<Dtype>::Backward(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down,
    vector<Blob<Dtype>*>* bottom) {
  const Dtype* top_diff = top[0]->const_diff();
  const Dtype* bottom_data = (*bottom)[0]->const_data();
  // Gradient with respect to weight
  DeviceFactory<Dtype>::GetDevice()->gemm(
      CblasTrans, CblasNoTrans, N_, K_, M_, (Dtype)1.,
      top_diff, bottom_data, (Dtype)0., this->blobs_[0]->mutable_diff());
  if (bias_term_) {
    // Gradient with respect to bias
    DeviceFactory<Dtype>::GetDevice()->gemv(
        CblasTrans, M_, N_, (Dtype)1., top_diff,
        reinterpret_cast<const Dtype*>(bias_multiplier_->const_data()),
        (Dtype)0., this->blobs_[1]->mutable_diff());
  }
  if (propagate_down[0]) {
    // Gradient with respect to bottom data
    DeviceFactory<Dtype>::GetDevice()->gemm(
        CblasNoTrans, CblasNoTrans, M_, K_, N_, (Dtype)1.,
        top_diff, this->blobs_[0]->const_data(), (Dtype)0.,
        (*bottom)[0]->mutable_diff());
  }
}

INSTANTIATE_CLASS(InnerProductLayer);

}  // namespace caffe
