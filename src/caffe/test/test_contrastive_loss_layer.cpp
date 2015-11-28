#include <algorithm>
#include <cmath>
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <cstdlib>
#include <cstring>
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
#include <vector>

#include "gtest/gtest.h"

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/filler.hpp"
<<<<<<< HEAD
#include "caffe/loss_layers.hpp"
=======
<<<<<<< HEAD
<<<<<<< HEAD
#include "caffe/loss_layers.hpp"
=======
#include "caffe/vision_layers.hpp"
>>>>>>> origin/BVLC/parallel
=======
#include "caffe/loss_layers.hpp"
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge

#include "caffe/test/test_caffe_main.hpp"
#include "caffe/test/test_gradient_check_util.hpp"

namespace caffe {

template <typename TypeParam>
class ContrastiveLossLayerTest : public MultiDeviceTest<TypeParam> {
  typedef typename TypeParam::Dtype Dtype;

 protected:
  ContrastiveLossLayerTest()
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
      : blob_bottom_data_i_(new Blob<Dtype>(512, 2, 1, 1)),
        blob_bottom_data_j_(new Blob<Dtype>(512, 2, 1, 1)),
        blob_bottom_y_(new Blob<Dtype>(512, 1, 1, 1)),
        blob_top_loss_(new Blob<Dtype>()) {
    // fill the values
    FillerParameter filler_param;
    filler_param.set_min(-1.0);
    filler_param.set_max(1.0);  // distances~=1.0 to test both sides of margin
    UniformFiller<Dtype> filler(filler_param);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
      : blob_bottom_data_i_(new Blob<Dtype>(128, 10, 1, 1)),
        blob_bottom_data_j_(new Blob<Dtype>(128, 10, 1, 1)),
        blob_bottom_y_(new Blob<Dtype>(128, 1, 1, 1)),
        blob_top_loss_(new Blob<Dtype>()) {
    // fill the values
    FillerParameter filler_param;
    filler_param.set_mean(0.0);
    filler_param.set_std(0.3);  // distances~=1.0 to test both sides of margin
    GaussianFiller<Dtype> filler(filler_param);
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
    filler.Fill(this->blob_bottom_data_i_);
    blob_bottom_vec_.push_back(blob_bottom_data_i_);
    filler.Fill(this->blob_bottom_data_j_);
    blob_bottom_vec_.push_back(blob_bottom_data_j_);
    for (int i = 0; i < blob_bottom_y_->count(); ++i) {
      blob_bottom_y_->mutable_cpu_data()[i] = caffe_rng_rand() % 2;  // 0 or 1
    }
    blob_bottom_vec_.push_back(blob_bottom_y_);
    blob_top_vec_.push_back(blob_top_loss_);
  }
  virtual ~ContrastiveLossLayerTest() {
    delete blob_bottom_data_i_;
    delete blob_bottom_data_j_;
    delete blob_bottom_y_;
    delete blob_top_loss_;
  }

  Blob<Dtype>* const blob_bottom_data_i_;
  Blob<Dtype>* const blob_bottom_data_j_;
  Blob<Dtype>* const blob_bottom_y_;
  Blob<Dtype>* const blob_top_loss_;
  vector<Blob<Dtype>*> blob_bottom_vec_;
  vector<Blob<Dtype>*> blob_top_vec_;
};

TYPED_TEST_CASE(ContrastiveLossLayerTest, TestDtypesAndDevices);

TYPED_TEST(ContrastiveLossLayerTest, TestForward) {
  typedef typename TypeParam::Dtype Dtype;
  LayerParameter layer_param;
  ContrastiveLossLayer<Dtype> layer(layer_param);
  layer.SetUp(this->blob_bottom_vec_, this->blob_top_vec_);
  layer.Forward(this->blob_bottom_vec_, this->blob_top_vec_);
  // manually compute to compare
  const Dtype margin = layer_param.contrastive_loss_param().margin();
  const int num = this->blob_bottom_data_i_->num();
  const int channels = this->blob_bottom_data_i_->channels();
  Dtype loss(0);
  for (int i = 0; i < num; ++i) {
    Dtype dist_sq(0);
    for (int j = 0; j < channels; ++j) {
      Dtype diff = this->blob_bottom_data_i_->cpu_data()[i*channels+j] -
          this->blob_bottom_data_j_->cpu_data()[i*channels+j];
      dist_sq += diff*diff;
    }
    if (this->blob_bottom_y_->cpu_data()[i]) {  // similar pairs
      loss += dist_sq;
    } else {
<<<<<<< HEAD
      Dtype dist = std::max<Dtype>(margin - sqrt(dist_sq), 0.0);
      loss += dist*dist;
=======
<<<<<<< HEAD
<<<<<<< HEAD
      Dtype dist = std::max<Dtype>(margin - sqrt(dist_sq), 0.0);
      loss += dist*dist;
=======
      loss += std::max(margin-dist_sq, Dtype(0));
>>>>>>> origin/BVLC/parallel
=======
      Dtype dist = std::max<Dtype>(margin - sqrt(dist_sq), 0.0);
      loss += dist*dist;
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
    }
  }
  loss /= static_cast<Dtype>(num) * Dtype(2);
  EXPECT_NEAR(this->blob_top_loss_->cpu_data()[0], loss, 1e-6);
}

TYPED_TEST(ContrastiveLossLayerTest, TestGradient) {
  typedef typename TypeParam::Dtype Dtype;
  LayerParameter layer_param;
  ContrastiveLossLayer<Dtype> layer(layer_param);
  layer.SetUp(this->blob_bottom_vec_, this->blob_top_vec_);
  GradientChecker<Dtype> checker(1e-2, 1e-2, 1701);
  // check the gradient for the first two bottom layers
  checker.CheckGradientExhaustive(&layer, this->blob_bottom_vec_,
      this->blob_top_vec_, 0);
  checker.CheckGradientExhaustive(&layer, this->blob_bottom_vec_,
      this->blob_top_vec_, 1);
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
TYPED_TEST(ContrastiveLossLayerTest, TestForwardLegacy) {
  typedef typename TypeParam::Dtype Dtype;
  LayerParameter layer_param;
  layer_param.mutable_contrastive_loss_param()->set_legacy_version(true);
  ContrastiveLossLayer<Dtype> layer(layer_param);
  layer.SetUp(this->blob_bottom_vec_, this->blob_top_vec_);
  layer.Forward(this->blob_bottom_vec_, this->blob_top_vec_);
  // manually compute to compare
  const Dtype margin = layer_param.contrastive_loss_param().margin();
  const int num = this->blob_bottom_data_i_->num();
  const int channels = this->blob_bottom_data_i_->channels();
  Dtype loss(0);
  for (int i = 0; i < num; ++i) {
    Dtype dist_sq(0);
    for (int j = 0; j < channels; ++j) {
      Dtype diff = this->blob_bottom_data_i_->cpu_data()[i*channels+j] -
          this->blob_bottom_data_j_->cpu_data()[i*channels+j];
      dist_sq += diff*diff;
    }
    if (this->blob_bottom_y_->cpu_data()[i]) {  // similar pairs
      loss += dist_sq;
    } else {
      loss += std::max(margin - dist_sq, Dtype(0.0));
    }
  }
  loss /= static_cast<Dtype>(num) * Dtype(2);
  EXPECT_NEAR(this->blob_top_loss_->cpu_data()[0], loss, 1e-6);
}

TYPED_TEST(ContrastiveLossLayerTest, TestGradientLegacy) {
  typedef typename TypeParam::Dtype Dtype;
  LayerParameter layer_param;
  layer_param.mutable_contrastive_loss_param()->set_legacy_version(true);
  ContrastiveLossLayer<Dtype> layer(layer_param);
  layer.SetUp(this->blob_bottom_vec_, this->blob_top_vec_);
  GradientChecker<Dtype> checker(1e-2, 1e-2, 1701);
  // check the gradient for the first two bottom layers
  checker.CheckGradientExhaustive(&layer, this->blob_bottom_vec_,
      this->blob_top_vec_, 0);
  checker.CheckGradientExhaustive(&layer, this->blob_bottom_vec_,
      this->blob_top_vec_, 1);
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}  // namespace caffe
