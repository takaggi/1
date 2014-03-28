// Copyright 2014 kloudkl@github

#ifndef CAFFE_REGULARIZER_HPP_
#define CAFFE_REGULARIZER_HPP_

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/proto/caffe.pb.h"

namespace caffe {

template<typename Dtype>
class Regularizer {
 public:
  explicit Regularizer(const RegularizerParameter& param)
      : coeff_(Dtype(param.coeff())) {
    if (coeff_ < 0) {
      LOG(FATAL)<<
      "Regularizer coefficient must be greater than or equal to zero";
    }
  }

  virtual ~Regularizer() {
  }

  virtual Dtype Regularize(Blob<Dtype>* bottom);
  virtual Dtype Regularize_cpu(Blob<Dtype>* bottom) = 0;
  virtual Dtype Regularize_gpu(Blob<Dtype>* bottom) = 0;

  inline Dtype coeff() {
    return coeff_;
  }
  inline void set_coeff(const Dtype coeff) {
    coeff_ = coeff;
  }

 protected:
  // the weight regularization coefficient
  Dtype coeff_;
  DISABLE_COPY_AND_ASSIGN(Regularizer);
};

#define MAKE_SIMPLE_REGULARIZER_CLASS(type) \
template<typename Dtype> \
class type##Regularizer : public Regularizer<Dtype> { \
  /* NOLINT_NEXT_LINE(whitespace/indent) */ \
 public: \
  type##Regularizer(const RegularizerParameter& param) \
      : Regularizer<Dtype>(param) { \
  } \
  \
  virtual ~type##Regularizer() { \
  } \
  \
  virtual Dtype Regularize_cpu(Blob<Dtype>* bottom); \
  virtual Dtype Regularize_gpu(Blob<Dtype>* bottom); \
  \
  /* NOLINT_NEXT_LINE(whitespace/indent) */ \
 protected: \
  DISABLE_COPY_AND_ASSIGN(type##Regularizer); \
}

MAKE_SIMPLE_REGULARIZER_CLASS(L1);
MAKE_SIMPLE_REGULARIZER_CLASS(L2);
MAKE_SIMPLE_REGULARIZER_CLASS(MaxNorm);

#define REG_TYPE(type) REG_TYPE_PASTE(type)
#define REG_TYPE_PASTE(type) RegularizerParameter_RegularizerType_##type

template<typename Dtype>
Regularizer<Dtype>* GetRegularizer(const RegularizerParameter& param);

}  // namespace caffe

#endif  // CAFFE_REGULARIZER_HPP_
