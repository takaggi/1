#ifdef USE_CUDNN
<<<<<<< HEAD
<<<<<<< HEAD
#include <vector>

=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
#include <vector>

=======
=======
>>>>>>> pod/caffe-merge
#include <algorithm>
#include <vector>

#include "caffe/layer.hpp"
>>>>>>> origin/BVLC/parallel
=======
#include <vector>

>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
#include "caffe/vision_layers.hpp"

namespace caffe {

template <typename Dtype>
void CuDNNReLULayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  ReLULayer<Dtype>::LayerSetUp(bottom, top);
  // initialize cuDNN
  CUDNN_CHECK(cudnnCreate(&handle_));
  cudnn::createTensor4dDesc<Dtype>(&bottom_desc_);
  cudnn::createTensor4dDesc<Dtype>(&top_desc_);
<<<<<<< HEAD
<<<<<<< HEAD
  handles_setup_ = true;
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
  handles_setup_ = true;
=======
=======
>>>>>>> pod/caffe-merge
>>>>>>> origin/BVLC/parallel
=======
  handles_setup_ = true;
>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
}

template <typename Dtype>
void CuDNNReLULayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  ReLULayer<Dtype>::Reshape(bottom, top);
  const int N = bottom[0]->num();
  const int K = bottom[0]->channels();
  const int H = bottom[0]->height();
  const int W = bottom[0]->width();
  cudnn::setTensor4dDesc<Dtype>(&bottom_desc_, N, K, H, W);
  cudnn::setTensor4dDesc<Dtype>(&top_desc_, N, K, H, W);
}

template <typename Dtype>
CuDNNReLULayer<Dtype>::~CuDNNReLULayer() {
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
=======
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> caffe
>>>>>>> pod/caffe-merge
  // Check that handles have been setup before destroying.
  if (!handles_setup_) { return; }

  cudnnDestroyTensorDescriptor(this->bottom_desc_);
  cudnnDestroyTensorDescriptor(this->top_desc_);
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
  cudnnDestroyTensor4dDescriptor(this->bottom_desc_);
  cudnnDestroyTensor4dDescriptor(this->top_desc_);
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
  cudnnDestroy(this->handle_);
}

INSTANTIATE_CLASS(CuDNNReLULayer);

}  // namespace caffe
#endif
