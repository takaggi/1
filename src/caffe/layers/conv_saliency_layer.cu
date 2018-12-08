#include <vector>

#include "caffe/filler.hpp"
#include "caffe/layers/conv_saliency_layer.hpp"

namespace caffe {


template <typename Dtype>
void ConvolutionSaliencyLayer<Dtype>::Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  const Dtype* weight = this->blobs_[0]->gpu_data();
  for (int i = 0; i < bottom.size(); ++i) {
    const Dtype* bottom_data = bottom[i]->gpu_data();
    Dtype* top_data = top[i]->mutable_gpu_data();
    for (int n = 0; n < this->num_; ++n) {
      this->forward_gpu_gemm(bottom_data + n * this->bottom_dim_, weight,
          top_data + n * this->top_dim_);
      if (this->bias_term_) {
        const Dtype* bias = this->blobs_[1]->gpu_data();
        this->forward_gpu_bias(top_data + n * this->top_dim_, bias);
      }
    }
  }
}

template <typename Dtype>
void ConvolutionSaliencyLayer<Dtype>::Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
  const Dtype* weight = this->blobs_[0]->gpu_data();
  Dtype* weight_diff = this->blobs_[0]->mutable_gpu_diff();
  for (int i = 0; i < top.size(); ++i) {
    const Dtype* top_diff = top[i]->gpu_diff();
    const Dtype* top_data = top[i]->gpu_data();
    const Dtype* bottom_data = bottom[i]->gpu_data();
    Dtype* bottom_diff = bottom[i]->mutable_gpu_diff();
    // Bias gradient, if necessary.
    if (this->bias_term_ && this->param_propagate_down_[1]) {
      Dtype* bias_diff = this->blobs_[1]->mutable_gpu_diff();
      for (int n = 0; n < this->num_; ++n) {
        this->backward_gpu_bias(bias_diff, top_diff + n * this->top_dim_);
      }
    }
    if (this->param_propagate_down_[0] || propagate_down[i]) {
      for (int n = 0; n < this->num_; ++n) {
        // gradient w.r.t. weight. Note that we will accumulate diffs.
        if (this->param_propagate_down_[0]) {
          this->weight_gpu_gemm(bottom_data + n * this->bottom_dim_,
              top_diff + n * this->top_dim_, weight_diff);
        }
        // gradient w.r.t. bottom data, if necessary.
        if (propagate_down[i]) {
          this->backward_gpu_gemm(top_diff + n * this->top_dim_, weight,
              bottom_diff + n * this->bottom_dim_);
        }
      }
    }

    Dtype* channel_saliency_data = output_saliencies_channel_.mutable_gpu_data();    
  
    switch (this->layer_param_.convolution_saliency_param().saliency()) {
      case (0): { // Fisher Information
        compute_fisher_gpu(top_data, top_diff, channel_saliency_data);
      } break;

      case (1): { // Taylor Series
        compute_taylor_gpu(top_data, top_diff, channel_saliency_data);
      } break;

      case (2): {
        compute_fisher_gpu(top_data, top_diff, channel_saliency_data);
        compute_taylor_gpu(top_data, top_diff, channel_saliency_data + this->num_output_);
      } break;

      default: {
      } break;
    }
    if (this->layer_param_.convolution_saliency_param().accum()) {
      caffe_gpu_add(output_saliencies_channel_.count(), output_saliencies_channel_.mutable_gpu_data(), this->blobs_[this->saliency_pos_]->mutable_gpu_data(), this->blobs_[this->saliency_pos_]->mutable_gpu_data()); 
    }
    else {
      caffe_copy(output_saliencies_channel_.count(), output_saliencies_channel_.mutable_gpu_data(), this->blobs_[this->saliency_pos_]->mutable_gpu_data());
    }
  }
}
template <typename Dtype>
void ConvolutionSaliencyLayer<Dtype>::compute_fisher_gpu(const Dtype *  act_data, const Dtype *  act_diff, Dtype * fisher_info) {
  Dtype* output_saliency_data = output_saliencies_points_.mutable_gpu_data();    
  Dtype* filter_saliency_data = output_saliencies_filter_.mutable_gpu_data();    
  
  caffe_gpu_mul(this->output_saliencies_points_.count(), act_data, act_diff, output_saliency_data);
  
  for (int i = 0; i < this->output_saliencies_points_.count(0, 2); ++i) { //mxc loop
    caffe_gpu_sum(output_saliencies_points_.count(2,4), output_saliency_data, filter_saliency_data); //sum hxw
    output_saliency_data += output_saliencies_points_.count(2,4);
    ++filter_saliency_data;
  }
  filter_saliency_data = output_saliencies_filter_.mutable_gpu_data();    
  
  caffe_gpu_powx(this->output_saliencies_filter_.count(), filter_saliency_data, (Dtype)2, filter_saliency_data);
  
  Dtype * original_channel = fisher_info;
  for (int i = 0; i < this->num_output_; ++i ) {
    caffe_gpu_sum(this->num_, filter_saliency_data, fisher_info, this->num_output_); // functionally it does not matter if we use sum or asum; sum across batches
    filter_saliency_data += 1;
    ++fisher_info;
  }
  fisher_info = original_channel;
  
  caffe_gpu_scal(this->num_output_, 1/(Dtype)(this->num_*2), fisher_info);
}

template <typename Dtype>
void ConvolutionSaliencyLayer<Dtype>::compute_taylor_gpu(const Dtype *  act_data, const Dtype *  act_diff, Dtype * taylor) {
  Dtype* output_saliency_data = output_saliencies_points_.mutable_gpu_data();    
  Dtype* filter_saliency_data = output_saliencies_filter_.mutable_gpu_data();    
  
  caffe_gpu_mul(this->output_saliencies_points_.count(), act_data, act_diff, output_saliency_data);
  caffe_gpu_abs(this->output_saliencies_points_.count(), output_saliency_data, output_saliency_data);
  
  for (int i = 0; i < this->output_saliencies_points_.count(0, 2); ++i) {
    caffe_gpu_sum(output_saliencies_points_.count(2,4), output_saliency_data, filter_saliency_data); //sum hxw
    output_saliency_data += output_saliencies_points_.count(2,4);
    ++filter_saliency_data;
  }
  filter_saliency_data = output_saliencies_filter_.mutable_gpu_data();    
  
  Dtype * original_channel = taylor;
  for (int i = 0; i < this->num_output_; ++i ) { 
    caffe_gpu_sum(this->num_, filter_saliency_data, taylor,this->num_output_); // functionally it does not matter if we use sum or asum; sum across batches
    filter_saliency_data += 1;
    ++taylor;
  }
  taylor = original_channel;
  
  caffe_gpu_scal(this->num_output_, 1/(Dtype)(this->num_*this->output_shape_[0]*this->output_shape_[1]), taylor);
  
}


#ifdef CPU_ONLY
STUB_GPU(ConvolutionSaliencyLayer);
#endif


INSTANTIATE_LAYER_GPU_FUNCS(ConvolutionSaliencyLayer);

}  // namespace caffe