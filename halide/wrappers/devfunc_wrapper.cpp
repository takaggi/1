#include "devfunc_wrapper.h"

#include "Halide.h"

// This is the header generated by halide
#include "blur_y.h"


using namespace Halide;

template <typename Dtype>
int inline DevFuncWrapper<Dtype>::ExactNumBottomBlobs() { return 1; }

template <typename Dtype>
int inline DevFuncWrapper<Dtype>::ExactNumTopBlobs() { return 1; }

template <typename Dtype>
void DevFuncWrapper<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top) {}

template <typename Dtype>
void DevFuncWrapper<Dtype>::Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  // There is an argv implementation of all halide functions
  // in case dynamic behaviour is needed.
  bottom_buf_ = HalideWrapBlob(*bottom[0]);
  top_buf_ = HalideWrapBlob(*top[0]);
  blur_y(&bottom_buf_, &top_buf_);
  HalideSyncBlob(bottom_buf_, bottom[0]);
  HalideSyncBlob(top_buf_, top[0]);
}

template <typename Dtype>
void DevFuncWrapper<Dtype>::Backward_gpu(const vector<Blob<Dtype>*>& top,
        const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
  bottom_diff_buf_ = HalideWrapBlob(*bottom[0], false);
  top_diff_buf_ = HalideWrapBlob(*top[0], false);
  blur_y(&top_diff_buf_, &bottom_diff_buf_);
  HalideSyncBlob(top_diff_buf_, top[0], false);
  HalideSyncBlob(bottom_diff_buf_, bottom[0], false);
}

template <typename Dtype>
void DevFuncWrapper<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  // This is a suitable place to check bottom shape
  top[0]->ReshapeLike(*bottom[0]);
}

// the class factories
extern "C" boost::shared_ptr<Layer<float> > getExtLayer(const LayerParameter& param) {
    return boost::shared_ptr<Layer<float> >(new DevFuncWrapper<float>(param));
}

extern "C" string GetExtLayerName() {
    return "DevFuncLayer";
}
