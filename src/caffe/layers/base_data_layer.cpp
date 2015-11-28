<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
#include <boost/thread.hpp>
#include <vector>

#include "caffe/data_layers.hpp"
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
#include <string>
#include <vector>

#include "caffe/data_layers.hpp"
#include "caffe/util/io.hpp"
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge

namespace caffe {

template <typename Dtype>
BaseDataLayer<Dtype>::BaseDataLayer(const LayerParameter& param)
    : Layer<Dtype>(param),
<<<<<<< HEAD
      transform_param_(param.transform_param()) {
=======
<<<<<<< HEAD
<<<<<<< HEAD
      transform_param_(param.transform_param()) {
=======
      transform_param_(param.transform_param()),
      data_transformer_(transform_param_) {
>>>>>>> origin/BVLC/parallel
=======
      transform_param_(param.transform_param()) {
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}

template <typename Dtype>
void BaseDataLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  if (top.size() == 1) {
    output_labels_ = false;
  } else {
    output_labels_ = true;
  }
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  data_transformer_.reset(
      new DataTransformer<Dtype>(transform_param_, this->phase_));
  data_transformer_->InitRand();
  // The subclasses should setup the size of bottom and top
  DataLayerSetUp(bottom, top);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
  // The subclasses should setup the size of bottom and top
  DataLayerSetUp(bottom, top);
  data_transformer_.InitRand();
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}

template <typename Dtype>
BasePrefetchingDataLayer<Dtype>::BasePrefetchingDataLayer(
    const LayerParameter& param)
    : BaseDataLayer<Dtype>(param),
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
      prefetch_free_(), prefetch_full_() {
  for (int i = 0; i < PREFETCH_COUNT; ++i) {
    prefetch_free_.push(&prefetch_[i]);
  }
<<<<<<< HEAD
}

template <typename Dtype>
BasePrefetchingDataLayer<Dtype>::BasePrefetchingDataLayer(
    const LayerParameter& param)
    : BaseDataLayer<Dtype>(param),
      prefetch_free_(), prefetch_full_(), device_() {
  for(int i = 0; i < PREFETCH_COUNT; ++i)
    prefetch_free_.push(&prefetch_[i]);
}

template <typename Dtype>
BasePrefetchingDataLayer<Dtype>::BasePrefetchingDataLayer(
    const LayerParameter& param)
    : BaseDataLayer<Dtype>(param),
      prefetch_free_(), prefetch_full_(), device_() {
  for(int i = 0; i < PREFETCH_COUNT; ++i)
    prefetch_free_.push(&prefetch_[i]);
}

template <typename Dtype>
BasePrefetchingDataLayer<Dtype>::BasePrefetchingDataLayer(
    const LayerParameter& param)
    : BaseDataLayer<Dtype>(param),
      prefetch_free_(), prefetch_full_(), device_() {
  for(int i = 0; i < PREFETCH_COUNT; ++i)
    prefetch_free_.push(&prefetch_[i]);
=======
<<<<<<< HEAD
=======
      prefetch_free_(), prefetch_full_(), device_() {
  for(int i = 0; i < PREFETCH_COUNT; ++i)
    prefetch_free_.push(&prefetch_[i]);
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}

template <typename Dtype>
void BasePrefetchingDataLayer<Dtype>::LayerSetUp(
    const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) {
  BaseDataLayer<Dtype>::LayerSetUp(bottom, top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> origin/BVLC/parallel
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======

>>>>>>> origin/BVLC/parallel
=======
<<<<<<< HEAD

>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  // Before starting the prefetch thread, we make cpu_data and gpu_data
  // calls so that the prefetch thread does not accidentally make simultaneous
  // cudaMalloc calls when the main thread is running. In some GPUs this
  // seems to cause failures if we do not so.
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
  for (int i = 0; i < PREFETCH_COUNT; ++i) {
=======
  for(int i = 0; i < PREFETCH_COUNT; ++i) {
>>>>>>> origin/BVLC/parallel
=======
<<<<<<< HEAD
  for(int i = 0; i < PREFETCH_COUNT; ++i) {
>>>>>>> origin/BVLC/parallel
=======
  for(int i = 0; i < PREFETCH_COUNT; ++i) {
>>>>>>> origin/BVLC/parallel
=======
  for (int i = 0; i < PREFETCH_COUNT; ++i) {
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
    prefetch_[i].data_.mutable_cpu_data();
    if (this->output_labels_) {
      prefetch_[i].label_.mutable_cpu_data();
    }
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  }
=======
  }
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
#ifndef CPU_ONLY
  if (Caffe::mode() == Caffe::GPU) {
    for (int i = 0; i < PREFETCH_COUNT; ++i) {
      prefetch_[i].data_.mutable_gpu_data();
      if (this->output_labels_) {
        prefetch_[i].label_.mutable_gpu_data();
      }
    }
  }
#endif
  DLOG(INFO) << "Initializing prefetch";
  this->data_transformer_->InitRand();
  StartInternalThread();
<<<<<<< HEAD
=======
  }
=======
  }
>>>>>>> origin/BVLC/parallel
=======
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
  switch (Caffe::mode()) {
    case Caffe::CPU:
      device_ = -1;
      break;
    case Caffe::GPU:
#ifndef CPU_ONLY
      for(int i = 0; i < PREFETCH_COUNT; ++i) {
        prefetch_[i].data_.mutable_gpu_data();
        if (this->output_labels_) {
          prefetch_[i].label_.mutable_gpu_data();
        }
      }
      CUDA_CHECK(cudaGetDevice(&device_));
#endif
      break;
  }

  DLOG(INFO) << "Initializing prefetch";
  this->phase_ = Caffe::phase();
  this->data_transformer_.InitRand();
  CHECK(StartInternalThread()) << "Thread execution failed";
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  DLOG(INFO) << "Prefetch initialized.";
}

template <typename Dtype>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
void BasePrefetchingDataLayer<Dtype>::InternalThreadEntry() {
#ifndef CPU_ONLY
  cudaStream_t stream;
  if (Caffe::mode() == Caffe::GPU) {
    CUDA_CHECK(cudaStreamCreateWithFlags(&stream, cudaStreamNonBlocking));
  }
#endif

  try {
    while (!must_stop()) {
      Batch<Dtype>* batch = prefetch_free_.pop();
      load_batch(batch);
#ifndef CPU_ONLY
      if (Caffe::mode() == Caffe::GPU) {
        batch->data_.data().get()->async_gpu_push(stream);
        CUDA_CHECK(cudaStreamSynchronize(stream));
      }
#endif
      prefetch_full_.push(batch);
    }
  } catch (boost::thread_interrupted&) {
    // Interrupted exception is expected on shutdown
  }
#ifndef CPU_ONLY
  if (Caffe::mode() == Caffe::GPU) {
    CUDA_CHECK(cudaStreamDestroy(stream));
  }
#endif
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
BasePrefetchingDataLayer<Dtype>::~BasePrefetchingDataLayer() {
  CHECK(StopInternalThread()) << "Stop thread failed";
}

template <typename Dtype>
<<<<<<< HEAD
=======
  }
  switch (Caffe::mode()) {
    case Caffe::CPU:
      device_ = -1;
      break;
    case Caffe::GPU:
#ifndef CPU_ONLY
      for(int i = 0; i < PREFETCH_COUNT; ++i) {
        prefetch_[i].data_.mutable_gpu_data();
        if (this->output_labels_) {
          prefetch_[i].label_.mutable_gpu_data();
        }
      }
      CUDA_CHECK(cudaGetDevice(&device_));
#endif
      break;
  }

  DLOG(INFO) << "Initializing prefetch";
  this->phase_ = Caffe::phase();
  this->data_transformer_.InitRand();
  CHECK(StartInternalThread()) << "Thread execution failed";
  DLOG(INFO) << "Prefetch initialized.";
}

template <typename Dtype>
BasePrefetchingDataLayer<Dtype>::~BasePrefetchingDataLayer() {
  CHECK(StopInternalThread()) << "Stop thread failed";
}

template <typename Dtype>
>>>>>>> origin/BVLC/parallel
=======
BasePrefetchingDataLayer<Dtype>::~BasePrefetchingDataLayer() {
  CHECK(StopInternalThread()) << "Stop thread failed";
}

template <typename Dtype>
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> pod-caffe-pod.hpp-merge
void BasePrefetchingDataLayer<Dtype>::InternalThreadEntry() {
#ifndef CPU_ONLY
  cudaStream_t stream;
  if(device_ >= 0) {
    CUDA_CHECK(cudaSetDevice(device_));
    cudaStreamCreateWithFlags(&stream, cudaStreamNonBlocking);
  }
#endif

  while(!must_stop()) {
    Batch<Dtype>* batch = prefetch_free_.pop();
    load_batch(batch);
#ifndef CPU_ONLY
    if(device_ >= 0) {
      batch->data_.data().get()->async_gpu_push(stream);
      cudaStreamSynchronize(stream);
    }
#endif
    prefetch_full_.push(batch);
  }
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
}

template <typename Dtype>
void BasePrefetchingDataLayer<Dtype>::Forward_cpu(
    const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) {
  Batch<Dtype>* batch = prefetch_full_.pop("Data layer prefetch queue empty");
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  // Reshape to loaded data.
  top[0]->ReshapeLike(batch->data_);
  // Copy the data
  caffe_copy(batch->data_.count(), batch->data_.cpu_data(),
             top[0]->mutable_cpu_data());
  DLOG(INFO) << "Prefetch copied";
  if (this->output_labels_) {
    // Reshape to loaded labels.
    top[1]->ReshapeLike(batch->label_);
    // Copy the labels.
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======

  caffe_copy(batch->data_.count(), batch->data_.cpu_data(),
      top[0]->mutable_cpu_data());
  if (this->output_labels_) {
>>>>>>> origin/BVLC/parallel
=======
<<<<<<< HEAD

  caffe_copy(batch->data_.count(), batch->data_.cpu_data(),
      top[0]->mutable_cpu_data());
  if (this->output_labels_) {
>>>>>>> origin/BVLC/parallel
=======

  caffe_copy(batch->data_.count(), batch->data_.cpu_data(),
      top[0]->mutable_cpu_data());
  if (this->output_labels_) {
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
    caffe_copy(batch->label_.count(), batch->label_.cpu_data(),
        top[1]->mutable_cpu_data());
  }

  prefetch_free_.push(batch);
}

#ifdef CPU_ONLY
STUB_GPU_FORWARD(BasePrefetchingDataLayer, Forward);
#endif

INSTANTIATE_CLASS(BaseDataLayer);
<<<<<<< HEAD
INSTANTIATE_CLASS(Batch);
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
INSTANTIATE_CLASS(Batch);
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
INSTANTIATE_CLASS(BasePrefetchingDataLayer);

}  // namespace caffe
