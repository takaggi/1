#ifndef CAFFE_COMMON_LAYERS_HPP_
#define CAFFE_COMMON_LAYERS_HPP_

#include <utility>
#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

namespace caffe {

/**
 * @brief Compute the index of the @f$ K @f$ max values for each datum across
 *        all dimensions @f$ (C \times H \times W) @f$.
 *
 * Intended for use after a classification layer to produce a prediction.
 * If parameter out_max_val is set to true, output is a vector of pairs
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
=======
<<<<<<< HEAD
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
=======
>>>>>>> caffe
>>>>>>> pod/caffe-merge
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> device-abstraction
=======
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
>>>>>>> caffe
>>>>>>> pod/caffe-merge
=======
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
 * (max_ind, max_val) for each image. The axis parameter specifies an axis
 * along which to maximise.
 *
 * NOTE: does not implement Backwards operation.
 */
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
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
=======
>>>>>>> pod/caffe-merge
<<<<<<< HEAD
=======
>>>>>>> pod/caffe-merge
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
>>>>>>> pod/device/blob.hpp
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
template <typename Dtype>
class ArgMaxLayer : public Layer<Dtype> {
 public:
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
                        vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
                        const vector<bool>& propagate_down,
                        vector<Blob<Dtype>*>* bottom) { NOT_IMPLEMENTED; }
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
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
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

  virtual inline const char* type() const { return "ArgMax"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
>>>>>>> BVLC/master
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
>>>>>>> pod/device/blob.hpp
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
=======
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
<<<<<<< HEAD
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
 *
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

=======
=======
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> pod/device/blob.hpp

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

=======

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> pod/device/blob.hpp
 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
<<<<<<< HEAD
};

/**
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> caffe
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> BVLC/master
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
 */
template <typename Dtype>
class ConcatLayer : public Layer<Dtype> {
 public:
  explicit ConcatLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
};

/**
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> caffe
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> BVLC/master
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
 */
template <typename Dtype>
class ConcatLayer : public Layer<Dtype> {
 public:
  explicit ConcatLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  Blob<Dtype> col_bob_;
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> BVLC/master
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> caffe
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
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

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
=======
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
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> caffe
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> BVLC/master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> BVLC/master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
=======
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
};

/**
=======
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
>>>>>>> BVLC/master
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
 */
=======
>>>>>>> master
template <typename Dtype>
class FlattenLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit FlattenLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Flatten"; }
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  int count_;
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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
>>>>>>> master
};
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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

/**
<<<<<<< HEAD
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> master
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> master
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD

>>>>>>> master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
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
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class MVNLayer : public Layer<Dtype> {
 public:
  explicit MVNLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
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

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
=======

  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
>>>>>>> master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
 * (max_ind, max_val) for each image.
 *
 * NOTE: does not implement Backwards operation.
 */
>>>>>>> origin/BVLC/parallel
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReductionLayer(const LayerParameter& param)
=======
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
>>>>>>> master
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) for each image.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
>>>>>>> origin/BVLC/parallel
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual inline const char* type() const { return "Embed"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K \times 1) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K \times 1) @f$
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> caffe
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
>>>>>>> caffe
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
<<<<<<< HEAD
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
=======
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
>>>>>>> caffe
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> caffe
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> caffe
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> caffe
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> master
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> master

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
=======
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
                        vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
                        const vector<bool>& propagate_down,
                        vector<Blob<Dtype>*>* bottom) { NOT_IMPLEMENTED; }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "ArgMax"; }
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
=======

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

=======
=======
>>>>>>> BVLC/device-abstraction
  Blob<Dtype> col_bob_;
>>>>>>> BVLC/device-abstraction
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
=======
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
=======
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> caffe
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Flatten"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> caffe
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master

<<<<<<< HEAD
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Reshape"; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod/device/blob.hpp
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  Blob<Dtype> col_bob_;
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> BVLC/master
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
=======
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
=======
=======
>>>>>>> BVLC/device-abstraction
  int count_;
>>>>>>> BVLC/device-abstraction
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
=======
>>>>>>> BVLC/device-abstraction
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

=======
>>>>>>> BVLC/master
=======
  Blob<Dtype> sum_multiplier_;
};

>>>>>>> BVLC/master
/**
=======
>>>>>>> master
=======
>>>>>>> pod-caffe-pod.hpp-merge
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> pod/device/blob.hpp
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
>>>>>>> pod/device/blob.hpp
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
=======
  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod/device/blob.hpp
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

<<<<<<< HEAD
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> caffe
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }
=======
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
/**
>>>>>>> caffe
=======
/**
>>>>>>> master
=======
/**
>>>>>>> master
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top);

=======
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

<<<<<<< HEAD
/**
<<<<<<< HEAD
=======
=======
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};
>>>>>>> pod/device/blob.hpp

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
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

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
=======
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
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> caffe
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> BVLC/master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> BVLC/master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
=======
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
};

/**
=======
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
>>>>>>> BVLC/master
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
 */
=======
>>>>>>> master
template <typename Dtype>
class FlattenLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit FlattenLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Flatten"; }
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  int count_;
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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

>>>>>>> pod/device/blob.hpp
  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
<<<<<<< HEAD
};

/**
 * @brief Index into the input blob along its first axis.
 *
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
=======
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
>>>>>>> pod/device/blob.hpp
=======
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
=======
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
>>>>>>> pod/caffe-merge
=======
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
>>>>>>> pod/device/blob.hpp
=======
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
=======
  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod/device/blob.hpp
=======
  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
>>>>>>> pod-caffe-pod.hpp-merge
=======
  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
>>>>>>> pod/caffe-merge
=======
  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
>>>>>>> pod/device/blob.hpp
=======
  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
>>>>>>> pod-caffe-pod.hpp-merge
=======
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
>>>>>>> master
};
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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

/**
<<<<<<< HEAD
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> master
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> master
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD

>>>>>>> master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
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
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class MVNLayer : public Layer<Dtype> {
 public:
  explicit MVNLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
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

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
=======

  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
>>>>>>> master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
 * (max_ind, max_val) for each image.
 *
 * NOTE: does not implement Backwards operation.
 */
>>>>>>> origin/BVLC/parallel
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReductionLayer(const LayerParameter& param)
=======
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
>>>>>>> master
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) for each image.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
>>>>>>> origin/BVLC/parallel
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual inline const char* type() const { return "Embed"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K \times 1) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K \times 1) @f$
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> caffe
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
>>>>>>> caffe
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
<<<<<<< HEAD
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
=======
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
>>>>>>> caffe
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> caffe
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> caffe
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> caffe
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> master
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> master

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
=======
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
                        vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
                        const vector<bool>& propagate_down,
                        vector<Blob<Dtype>*>* bottom) { NOT_IMPLEMENTED; }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "ArgMax"; }
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
=======

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

=======
=======
>>>>>>> BVLC/device-abstraction
  Blob<Dtype> col_bob_;
>>>>>>> BVLC/device-abstraction
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
=======
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
=======
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> caffe
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Flatten"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> caffe
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod/device/blob.hpp
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
<<<<<<< HEAD
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
=======
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
>>>>>>> pod/device/blob.hpp
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> pod-caffe-pod.hpp-merge
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> pod/caffe-merge
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> caffe
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> BVLC/master
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
 */
template <typename Dtype>
class ConcatLayer : public Layer<Dtype> {
 public:
  explicit ConcatLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
=======
=======
>>>>>>> BVLC/device-abstraction
  int count_;
>>>>>>> BVLC/device-abstraction
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
=======
>>>>>>> BVLC/device-abstraction
>>>>>>> pod/device/blob.hpp
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
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
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  Blob<Dtype> col_bob_;
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> BVLC/master
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
=======
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

=======
>>>>>>> BVLC/master
=======
  Blob<Dtype> sum_multiplier_;
};

>>>>>>> BVLC/master
/**
=======
>>>>>>> master
=======
>>>>>>> pod-caffe-pod.hpp-merge
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> pod/device/blob.hpp
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
>>>>>>> pod/device/blob.hpp
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
=======
  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod/device/blob.hpp
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

<<<<<<< HEAD
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> caffe
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }
=======
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
/**
>>>>>>> caffe
=======
/**
>>>>>>> master
=======
/**
>>>>>>> master
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top);

=======
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

<<<<<<< HEAD
/**
<<<<<<< HEAD
=======
=======
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};
>>>>>>> pod/device/blob.hpp

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
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

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
=======
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
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> caffe
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> BVLC/master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> BVLC/master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
=======
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
};

/**
=======
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
>>>>>>> BVLC/master
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
 */
=======
>>>>>>> master
template <typename Dtype>
class FlattenLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit FlattenLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Flatten"; }
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  int count_;
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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
>>>>>>> master
};
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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

/**
<<<<<<< HEAD
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> master
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> master
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD

>>>>>>> master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
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
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class MVNLayer : public Layer<Dtype> {
 public:
  explicit MVNLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
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

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
=======

  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
>>>>>>> master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
 * (max_ind, max_val) for each image.
 *
 * NOTE: does not implement Backwards operation.
 */
>>>>>>> origin/BVLC/parallel
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReductionLayer(const LayerParameter& param)
=======
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
>>>>>>> master
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) for each image.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
>>>>>>> origin/BVLC/parallel
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual inline const char* type() const { return "Embed"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K \times 1) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K \times 1) @f$
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> caffe
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
>>>>>>> caffe
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
<<<<<<< HEAD
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
=======
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
>>>>>>> caffe
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> caffe
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> caffe
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> caffe
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> master
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> master

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};
<<<<<<< HEAD

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
=======
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
                        vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
                        const vector<bool>& propagate_down,
                        vector<Blob<Dtype>*>* bottom) { NOT_IMPLEMENTED; }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "ArgMax"; }
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> pod/device/blob.hpp
 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
<<<<<<< HEAD
};

/**
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> caffe
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> BVLC/master
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
 */
template <typename Dtype>
class ConcatLayer : public Layer<Dtype> {
 public:
  explicit ConcatLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
=======

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

=======
=======
>>>>>>> BVLC/device-abstraction
  Blob<Dtype> col_bob_;
>>>>>>> BVLC/device-abstraction
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
=======
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
=======
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> caffe
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Flatten"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> caffe
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master

<<<<<<< HEAD
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Reshape"; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod/device/blob.hpp
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  Blob<Dtype> col_bob_;
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> pod/device/blob.hpp

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
<<<<<<< HEAD
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
=======
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
>>>>>>> pod/device/blob.hpp
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
>>>>>>> BVLC/master
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
=======
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
=======
=======
>>>>>>> BVLC/device-abstraction
  int count_;
>>>>>>> BVLC/device-abstraction
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
>>>>>>> pod/device/blob.hpp
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> caffe
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
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

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
=======
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
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
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
  virtual inline const char* type() const { return "MVN"; }
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
=======
>>>>>>> BVLC/device-abstraction
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

=======
>>>>>>> BVLC/master
=======
  Blob<Dtype> sum_multiplier_;
};

>>>>>>> BVLC/master
/**
=======
>>>>>>> master
=======
>>>>>>> pod-caffe-pod.hpp-merge
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> pod/device/blob.hpp
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
>>>>>>> pod/device/blob.hpp
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
=======
  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod/device/blob.hpp
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> caffe
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> BVLC/master
  virtual inline int ExactNumTopBlobs() const { return 1; }
=======
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }
>>>>>>> pod/device/blob.hpp

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
/**
>>>>>>> caffe
=======
/**
>>>>>>> master
=======
/**
>>>>>>> master
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top);

=======
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

<<<<<<< HEAD
/**
<<<<<<< HEAD
=======
=======
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
>>>>>>> pod/device/blob.hpp
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }
=======
<<<<<<< HEAD
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
>>>>>>> master
=======
  /// sum_multiplier is used to carry out sum using BLAS
>>>>>>> origin/BVLC/parallel
  Blob<Dtype> sum_multiplier_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> origin/BVLC/parallel
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

<<<<<<< HEAD
  virtual inline const char* type() const { return "Silence"; }
=======
  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_SILENCE;
  }
>>>>>>> origin/BVLC/parallel
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }
>>>>>>> pod/device/blob.hpp

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
<<<<<<< HEAD
=======
  virtual inline const char* type() const { return "Embed"; }
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> origin/BVLC/parallel
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class SoftmaxLayer : public Layer<Dtype> {
 public:
  explicit SoftmaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Softmax"; }
>>>>>>> pod/device/blob.hpp
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
=======
<<<<<<< HEAD
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
<<<<<<< HEAD
<<<<<<< HEAD
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
>>>>>>> origin/BVLC/parallel
=======
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  /// scale is an intermediate Blob to hold temporary results.
  Blob<Dtype> scale_;
>>>>>>> pod/device/blob.hpp
};

/**
>>>>>>> BVLC/master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit FilterLayer(const LayerParameter& param)
=======
>>>>>>> master
      : Layer<Dtype>(param) {}
=======
  explicit CuDNNSoftmaxLayer(const LayerParameter& param)
<<<<<<< HEAD
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
<<<<<<< HEAD
<<<<<<< HEAD
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
      : SoftmaxLayer<Dtype>(param) {}
>>>>>>> origin/BVLC/parallel
=======
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
};

/**
=======
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
>>>>>>> BVLC/master
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
 */
=======
>>>>>>> master
template <typename Dtype>
class FlattenLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit FlattenLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Flatten"; }
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  int count_;
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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
>>>>>>> master
};
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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

/**
<<<<<<< HEAD
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> master
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> master
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD

>>>>>>> master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
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
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class MVNLayer : public Layer<Dtype> {
 public:
  explicit MVNLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
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

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
=======

  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
>>>>>>> master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
 * (max_ind, max_val) for each image.
 *
 * NOTE: does not implement Backwards operation.
 */
>>>>>>> origin/BVLC/parallel
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReductionLayer(const LayerParameter& param)
=======
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
>>>>>>> master
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) for each image.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
>>>>>>> origin/BVLC/parallel
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual inline const char* type() const { return "Embed"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K \times 1) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K \times 1) @f$
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> caffe
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
>>>>>>> caffe
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
<<<<<<< HEAD
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
=======
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
>>>>>>> caffe
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> caffe
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> caffe
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> caffe
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> master
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> master

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
=======
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
                        vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
                        const vector<bool>& propagate_down,
                        vector<Blob<Dtype>*>* bottom) { NOT_IMPLEMENTED; }
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "ArgMax"; }
=======

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
=======
>>>>>>> BVLC/device-abstraction
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
=======
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
>>>>>>> pod-caffe-pod.hpp-merge
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
<<<<<<< HEAD
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
=======
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
>>>>>>> pod-caffe-pod.hpp-merge
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
=======
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
=======

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

=======
  Blob<Dtype> col_bob_;
>>>>>>> BVLC/device-abstraction
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
=======
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
=======
  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
=======
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
=======

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Embed"; }
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
=======
  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
<<<<<<< HEAD
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
>>>>>>> pod-caffe-pod.hpp-merge
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
=======
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
=======
=======

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> caffe
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Flatten"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> caffe
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
=======

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> pod/caffe-merge
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod/caffe-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
>>>>>>> pod/caffe-merge
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  virtual inline const char* type() const { return "InnerProduct"; }
=======

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
>>>>>>> pod/caffe-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe
>>>>>>> pod/caffe-merge

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
<<<<<<< HEAD
=======
  int count_;
>>>>>>> BVLC/device-abstraction
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

=======
=======
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> pod/caffe-merge
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
<<<<<<< HEAD
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> caffe
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> caffe
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
>>>>>>> pod-caffe-pod.hpp-merge
=======
  virtual inline const char* type() const { return "Reshape"; }
>>>>>>> pod/caffe-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
>>>>>>> BVLC/device-abstraction

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

=======
>>>>>>> BVLC/master
=======
  Blob<Dtype> sum_multiplier_;
};

>>>>>>> BVLC/master
/**
=======
>>>>>>> master
=======
>>>>>>> pod-caffe-pod.hpp-merge
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
=======
/**
>>>>>>> caffe
=======
/**
>>>>>>> master
=======
/**
>>>>>>> master
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
=======

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> pod/caffe-merge
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD
};

<<<<<<< HEAD
/**
<<<<<<< HEAD
=======
=======
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
>>>>>>> pod/caffe-merge
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
>>>>>>> pod/caffe-merge
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
>>>>>>> pod/caffe-merge
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod/caffe-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
>>>>>>> pod/caffe-merge
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
<<<<<<< HEAD
=======
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
>>>>>>> pod/caffe-merge

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
>>>>>>> pod/caffe-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
=======
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
>>>>>>> pod/caffe-merge
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  virtual inline const char* type() const { return "Reduction"; }
=======

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
=======

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
>>>>>>> pod/device/blob.hpp
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
<<<<<<< HEAD
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
>>>>>>> pod/caffe-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
>>>>>>> pod/caffe-merge
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> pod/caffe-merge
=======
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

>>>>>>> pod/caffe-merge
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

=======
>>>>>>> BVLC/master
=======
  Blob<Dtype> sum_multiplier_;
};

=======
>>>>>>> BVLC/master
=======
  Blob<Dtype> sum_multiplier_;
};

>>>>>>> BVLC/master
/**
=======
>>>>>>> master
>>>>>>> pod/caffe-merge
=======
  Blob<Dtype> sum_multiplier_;
};

<<<<<<< HEAD
>>>>>>> BVLC/master
/**
=======
>>>>>>> master
=======
>>>>>>> pod-caffe-pod.hpp-merge
  Blob<Dtype> sum_multiplier_;
};

/**
<<<<<<< HEAD
=======
/**
>>>>>>> caffe
=======
/**
>>>>>>> master
=======
/**
>>>>>>> master
>>>>>>> pod/caffe-merge
=======
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> caffe
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
>>>>>>> pod/caffe-merge
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
=======
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> pod/device/blob.hpp
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod/caffe-merge

<<<<<<< HEAD
  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }
=======
  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }
>>>>>>> pod/device/blob.hpp

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> caffe
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> BVLC/master
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
 */
template <typename Dtype>
class ConcatLayer : public Layer<Dtype> {
 public:
  explicit ConcatLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  Blob<Dtype> col_bob_;
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> BVLC/master
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> caffe
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> master
=======

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> BVLC/master
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
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

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
=======
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
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
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
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> BVLC/master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> caffe
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> BVLC/master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> master
=======
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
=======
  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> BVLC/master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
=======
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
};

/**
=======
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
>>>>>>> master
=======
};

/**
>>>>>>> master
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> caffe
=======
>>>>>>> master
=======
>>>>>>> master
=======
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
>>>>>>> BVLC/master
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
 */
=======
>>>>>>> master
template <typename Dtype>
class FlattenLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit FlattenLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Flatten"; }
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  int count_;
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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
>>>>>>> master
};
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
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

/**
<<<<<<< HEAD
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> master
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> master
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

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
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> master
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> master
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> master
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD

>>>>>>> master
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
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
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class MVNLayer : public Layer<Dtype> {
 public:
  explicit MVNLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
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

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/master
=======
=======
>>>>>>> caffe
=======
=======
>>>>>>> master
=======
>>>>>>> BVLC/master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
=======

  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> master
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
>>>>>>> master
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
>>>>>>> master
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
 * (max_ind, max_val) for each image.
 *
 * NOTE: does not implement Backwards operation.
 */
>>>>>>> origin/BVLC/parallel
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReductionLayer(const LayerParameter& param)
=======
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
>>>>>>> master
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) for each image.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
>>>>>>> origin/BVLC/parallel
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual inline const char* type() const { return "Embed"; }
>>>>>>> master
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K \times 1) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K \times 1) @f$
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> master
 */
=======
>>>>>>> caffe
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
>>>>>>> caffe
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
<<<<<<< HEAD
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if concat_dim == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if concat_dim == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
=======
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
>>>>>>> caffe
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
>>>>>>> caffe
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
>>>>>>> caffe
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
>>>>>>> caffe
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> master
=======
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
=======
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> caffe
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> master
=======
  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> master

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
=======
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
                        vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
                        const vector<bool>& propagate_down,
                        vector<Blob<Dtype>*>* bottom) { NOT_IMPLEMENTED; }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "ArgMax"; }
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> pod-caffe-pod.hpp-merge
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
=======

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

=======
=======
>>>>>>> BVLC/device-abstraction
  Blob<Dtype> col_bob_;
>>>>>>> BVLC/device-abstraction
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
=======
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
=======
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
=======
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> caffe
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
>>>>>>> pod-caffe-pod.hpp-merge
 */
=======
>>>>>>> device-abstraction
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
<<<<<<< HEAD
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
=======
=======
  /**
   * @param param provides ArgMaxParameter argmax_param,
   *     with ArgMaxLayer options:
   *   - top_k (\b optional uint, default 1).
   *     the number @f$ K @f$ of maximal items to output.
   *   - out_max_val (\b optional bool, default false).
   *     if set, output a vector of pairs (max_ind, max_val) unless axis is set then
   *     output max_val along the specified axis.
   *   - axis (\b optional int).
   *     if set, maximise along the specified axis else maximise the flattened
   *     trailing dimensions for each index of the first / num dimension.
   */
  explicit ArgMaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
>>>>>>> device-abstraction
                        vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
                        const vector<bool>& propagate_down,
                        vector<Blob<Dtype>*>* bottom) { NOT_IMPLEMENTED; }
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Flatten"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> pod/device/blob.hpp
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
<<<<<<< HEAD
<<<<<<< HEAD
 */
=======
>>>>>>> caffe
=======
/**
>>>>>>> master
=======
/**
>>>>>>> master
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
=======
>>>>>>> caffe
>>>>>>> pod/device/blob.hpp
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
<<<<<<< HEAD
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
=======
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> pod/device/blob.hpp
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
=======
      const vector<Blob<Dtype>*>& top) {}

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
  virtual inline const char* type() const { return "Reshape"; }
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "ArgMax"; }
>>>>>>> device-abstraction
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
>>>>>>> pod/device/blob.hpp
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
  bool out_max_val_;
  size_t top_k_;
>>>>>>> BVLC/device-abstraction
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
=======
  /**
   * @param bottom input Blob vector (length 1)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times 1 \times K) @f$ or, if out_max_val
   *      @f$ (N \times 2 \times K) @f$ unless axis set than e.g.
   *      @f$ (N \times K \times H \times W) @f$ if axis == 1
   *      the computed outputs @f$
   *       y_n = \arg\max\limits_i x_{ni}
   *      @f$ (for @f$ K = 1 @f$).
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  /// @brief Not implemented (non-differentiable function)
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
    NOT_IMPLEMENTED;
  }
>>>>>>> BVLC/master
  bool out_max_val_;
  size_t top_k_;
  bool has_axis_;
  int axis_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance across
 *        the batch.
 *
 * This layer computes Batch Normalization described in [1].  For
 * each channel in the data (i.e. axis 1), it subtracts the mean and divides
 * by the variance, where both statistics are computed across both spatial
 * dimensions and across the different examples in the batch.
 *
 * By default, during training time, the network is computing global mean/
 * variance statistics via a running average, which is then used at test
 * time to allow deterministic outputs for each input.  You can manually
 * toggle whether the network is accumulating or using the statistics via the
 * use_global_stats option.  IMPORTANT: for this feature to work, you MUST
 * set the learning rate to zero for all three parameter blobs, i.e.,
 * param {lr_mult: 0} three times in the layer definition.
 *
 * Note that the original paper also included a per-channel learned bias and
 * scaling factor.  It is possible (though a bit cumbersome) to implement
 * this in caffe using a single-channel DummyDataLayer filled with zeros,
 * followed by a Convolution layer with output the same size as the current.
 * This produces a channel-specific value that can be added or multiplied by
 * the BatchNorm layer's output.
 *
 * [1] S. Ioffe and C. Szegedy, "Batch Normalization: Accelerating Deep Network
 *     Training by Reducing Internal Covariate Shift." arXiv preprint
 *     arXiv:1502.03167 (2015).
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class BatchNormLayer : public Layer<Dtype> {
 public:
  explicit BatchNormLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchNorm"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  Blob<Dtype> mean_, variance_, temp_, x_norm_;
  bool use_global_stats_;
  Dtype moving_average_fraction_;
  int channels_;
  Dtype eps_;

  // extra temporarary variables is used to carry out sums/broadcasting
  // using BLAS
  Blob<Dtype> batch_sum_multiplier_;
  Blob<Dtype> num_by_chans_;
  Blob<Dtype> spatial_sum_multiplier_;
};

/**
 * @brief Index into the input blob along its first axis.
 *
 * This layer can be used to select, reorder, and even replicate examples in a
 * batch.  The second blob is cast to int and treated as an index into the
 * first axis of the first blob.
 */
template <typename Dtype>
class BatchReindexLayer : public Layer<Dtype> {
 public:
  explicit BatchReindexLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "BatchReindex"; }
  virtual inline int ExactNumBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times ...) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (M) @f$
   *      the inputs @f$ x_2 @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (M \times ...) @f$:
   *      the reindexed array @f$
   *        y = x_1[x_2]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the reordered input.
   *
   * @param top output Blob vector (length 1), providing the error gradient
   *        with respect to the outputs
   *   -# @f$ (M \times ...) @f$:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2):
   *   - @f$ \frac{\partial E}{\partial y} @f$ is de-indexed (summing where
   *     required) back to the input x_1
   *   - This layer cannot backprop to x_2, i.e. propagate_down[1] must be
   *     false.
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

 private:
  struct pair_sort_first {
    bool operator()(const std::pair<int, int> &left,
                    const std::pair<int, int> &right) {
      return left.first < right.first;
    }
  };
  void check_batch_reindex(int initial_num, int final_num,
                           const Dtype* ridx_data);
};

/**
 * @brief Takes at least two Blob%s and concatenates them along either the num
 *        or channel dimension, outputting the result.
 */
>>>>>>> device-abstraction
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
=======
>>>>>>> device-abstraction
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
=======
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Concat"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  Blob<Dtype> col_bob_;
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_1 @f$
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_2 @f$
   *   -# ...
   *   - K @f$ (N \times C \times H \times W) @f$
   *      the inputs @f$ x_K @f$
   * @param top output Blob vector (length 1)
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      the concatenated output @f$
   *        y = [\begin{array}{cccc} x_1 & x_2 & ... & x_K \end{array}]
   *      @f$
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   *   -# @f$ (KN \times C \times H \times W) @f$ if axis == 0, or
   *      @f$ (N \times KC \times H \times W) @f$ if axis == 1:
   *      containing error gradients @f$ \frac{\partial E}{\partial y} @f$
   *      with respect to concatenated outputs @f$ y @f$
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top gradient
   *        @f$ \frac{\partial E}{\partial y} @f$ is deconcatenated back to the
   *        inputs @f$
   *        \left[ \begin{array}{cccc}
   *          \frac{\partial E}{\partial x_1} &
   *          \frac{\partial E}{\partial x_2} &
   *          ... &
   *          \frac{\partial E}{\partial x_K}
   *        \end{array} \right] =
   *        \frac{\partial E}{\partial y}
   *        @f$
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> BVLC/master
  int count_;
  int num_concats_;
  int concat_input_size_;
  int concat_axis_;
};

/**
 * @brief Compute elementwise operations, such as product and sum,
 *        along multiple input Blobs.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Eltwise"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
>>>>>>> device-abstraction
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
<<<<<<< HEAD
<<<<<<< HEAD
=======

=======

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief A layer for learning "embeddings" of one-hot vector input.
 *        Equivalent to an InnerProductLayer with one-hot vectors as input, but
 *        for efficiency the input is the "hot" index of each column itself.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class EmbedLayer : public Layer<Dtype> {
 public:
  explicit EmbedLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Embed"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

>>>>>>> device-abstraction
  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/device-abstraction
=======
  Blob<Dtype> col_bob_;
>>>>>>> BVLC/device-abstraction
  int count_;
>>>>>>> BVLC/device-abstraction
>>>>>>> pod/device/blob.hpp
};

<<<<<<< HEAD
/**
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
>>>>>>> caffe
>>>>>>> pod/caffe-merge
=======
};

/**
 * @brief Takes two+ Blobs, interprets last Blob as a selector and
 *  filter remaining Blobs accordingly with selector data (0 means that
 * the corresponding item has to be filtered, non-zero means that corresponding
 * item needs to stay).
 */
template <typename Dtype>
class FilterLayer : public Layer<Dtype> {
 public:
  explicit FilterLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Filter"; }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_1 @f$
   *   -# ...
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs to be filtered @f$ x_K @f$
   *   -# @f$ (N \times 1 \times 1 \times 1) @f$
   *      the selector blob
   * @param top output Blob vector (length 1+)
   *   -# @f$ (S \times C \times H \times W) @f$ ()
   *        the filtered output @f$ x_1 @f$
   *        where S is the number of items
   *        that haven't been filtered
   *      @f$ (S \times C \times H \times W) @f$
   *        the filtered output @f$ x_K @f$
   *        where S is the number of items
   *        that haven't been filtered
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
    const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the forwarded inputs.
   *
   * @param top output Blob vector (length 1+), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length 2+), into which the top error
   *        gradient is copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
    const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  bool first_reshape_;
  vector<int> indices_to_forward_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> device-abstraction
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
=======
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
=======
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> pod-caffe-pod.hpp-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
>>>>>>> pod/device/blob.hpp
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
=======
=======
>>>>>>> device-abstraction
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction

=======

  virtual inline const char* type() const { return "MVN"; }
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> device-abstraction
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
 protected:
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
=======
>>>>>>> BVLC/device-abstraction
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  /// sum_multiplier is used to carry out sum using BLAS
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

=======
>>>>>>> BVLC/master
=======
  Blob<Dtype> sum_multiplier_;
=======
  int count_;
>>>>>>> BVLC/device-abstraction
};

>>>>>>> BVLC/master
/**
=======
>>>>>>> master
=======
>>>>>>> pod-caffe-pod.hpp-merge
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
=======
  int count_;
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
=======

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "InnerProduct"; }
=======
  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
>>>>>>> BVLC/master
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> device-abstraction
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
=======
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
>>>>>>> pod-caffe-pod.hpp-merge
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
<<<<<<< HEAD
>>>>>>> device-abstraction
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
<<<<<<< HEAD
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
=======

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "Reduction"; }
=======
  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_ELTWISE;
  }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod/caffe-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

=======
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
=======
>>>>>>> device-abstraction
 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
=======
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
>>>>>>> pod-caffe-pod.hpp-merge
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
<<<<<<< HEAD
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> BVLC/master
>>>>>>> device-abstraction

 protected:
  Blob<Dtype> mean_, variance_, temp_;
>>>>>>> BVLC/device-abstraction

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/device/blob.hpp
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
<<<<<<< HEAD
=======
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
>>>>>>> pod/caffe-merge

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
=======
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
>>>>>>> pod/caffe-merge
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
<<<<<<< HEAD
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
=======
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
=======

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> caffe
 */
template <typename Dtype>
class EltwiseLayer : public Layer<Dtype> {
 public:
  explicit EltwiseLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
<<<<<<< HEAD
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
    return LayerParameter_LayerType_ELTWISE;
  }
  virtual inline int MinBottomBlobs() const { return 2; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  EltwiseParameter_EltwiseOp op_;
  vector<Dtype> coeffs_;
  Blob<int> max_idx_;

  bool stable_prod_grad_;
};

/**
 * @brief Reshapes the input Blob into flat vectors.
 *
 * Note: because this layer does not change the input values -- merely the
 * dimensions -- it can simply copy the input. The copy happens "virtually"
 * (thus taking effectively 0 real time) by setting, in Forward, the data
 * pointer of the top Blob to that of the bottom Blob (see Blob::ShareData),
 * and in Backward, the diff pointer of the bottom Blob to that of the top Blob
 * (see Blob::ShareDiff).
>>>>>>> origin/BVLC/parallel
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
>>>>>>> pod-caffe-pod.hpp-merge
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
>>>>>>> pod/caffe-merge
=======
  virtual inline const char* type() const { return "Flatten"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

>>>>>>> pod-caffe-pod.hpp-merge
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
=======
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
=======
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
=======
  /**
   * @param bottom input Blob vector (length 2+)
   *   -# @f$ (N \times C \times H \times W) @f$
   *      the inputs
   * @param top output Blob vector (length 1)
   *   -# @f$ (N \times CHW \times 1 \times 1) @f$
   *      the outputs -- i.e., the (virtually) copied, flattened inputs
   */
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  /**
   * @brief Computes the error gradient w.r.t. the concatenate inputs.
   *
   * @param top output Blob vector (length 1), providing the error gradient with
   *        respect to the outputs
   * @param propagate_down see Layer::Backward.
   * @param bottom input Blob vector (length K), into which the top error
   *        gradient is (virtually) copied
   */
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Also known as a "fully-connected" layer, computes an inner product
 *        with a set of learned weights, and (optionally) adds biases.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
>>>>>>> pod-caffe-pod.hpp-merge
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD

  virtual inline const char* type() const { return "Reshape"; }
=======

  virtual inline const char* type() const { return "InnerProduct"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class InnerProductLayer : public Layer<Dtype> {
 public:
  explicit InnerProductLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_INNER_PRODUCT;
  }
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "MVN"; }
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

=======
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

  int M_;
  int K_;
  int N_;
  bool bias_term_;
  Blob<Dtype> bias_multiplier_;
};

<<<<<<< HEAD
/**
 * @brief Normalizes the input to have 0-mean and/or unit (1) variance.
>>>>>>> origin/BVLC/parallel
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

>>>>>>> pod-caffe-pod.hpp-merge
  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
>>>>>>> caffe
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
>>>>>>> origin/BVLC/parallel
=======
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
<<<<<<< HEAD
<<<<<<< HEAD
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
=======
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> origin/BVLC/parallel
=======
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
>>>>>>> caffe

<<<<<<< HEAD
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
  /// sum_multiplier is used to carry out sum using BLAS
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> pod/device/blob.hpp
=======
  /// sum_multiplier is used to carry out sum using BLAS
>>>>>>> device-abstraction
=======
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> BVLC/master
=======
>>>>>>> BVLC/master
=======
>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/**
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> pod/device/blob.hpp
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
=======
=======
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
                        vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
                        const vector<bool>& propagate_down,
                        vector<Blob<Dtype>*>* bottom) { NOT_IMPLEMENTED; }
>>>>>>> BVLC/device-abstraction

=======
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

=======
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

>>>>>>> pod/caffe-merge
=======
=======
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
>>>>>>> caffe
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
=======
  bool out_max_val_;
  size_t top_k_;
>>>>>>> BVLC/device-abstraction
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
=======
  Blob<Dtype> col_bob_;
  int count_;
>>>>>>> BVLC/device-abstraction
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
  Blob<Dtype> sum_multiplier_;
};

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/**
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
=======
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
>>>>>>> device-abstraction
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top) {}

<<<<<<< HEAD
=======
>>>>>>> master
=======
  /// sum_multiplier is used to carry out sum using BLAS
>>>>>>> origin/BVLC/parallel
=======
  Blob<Dtype> sum_multiplier_;
};

=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> BVLC/master
=======
  Blob<Dtype> sum_multiplier_;
};

>>>>>>> BVLC/master
/**
=======
>>>>>>> master
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  Blob<Dtype> sum_multiplier_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> origin/BVLC/parallel
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> caffe
=======
/**
>>>>>>> master
=======
/**
>>>>>>> master
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======

=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

<<<<<<< HEAD
<<<<<<< HEAD
=======
  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======

/**
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
=======
/**
>>>>>>> caffe
=======
/**
>>>>>>> master
=======
/**
>>>>>>> master
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
>>>>>>> pod-caffe-pod.hpp-merge
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
<<<<<<< HEAD
      const vector<Blob<Dtype>*>& top);

=======
      const vector<Blob<Dtype>*>& top) {}

=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Silence"; }
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge

<<<<<<< HEAD
/**
<<<<<<< HEAD
=======
=======
=======
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  Dtype eps_;
};

/*
 * @brief Reshapes the input Blob into an arbitrary-sized output Blob.
 *
 * Note: similarly to FlattenLayer, this layer does not change the input values
 * (see FlattenLayer, Blob::ShareData and Blob::ShareDiff).
 */
template <typename Dtype>
class ReshapeLayer : public Layer<Dtype> {
 public:
  explicit ReshapeLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reshape"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
<<<<<<< HEAD
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {}

  /// @brief vector of axes indices whose dimensions we'll copy from the bottom
  vector<int> copy_axes_;
  /// @brief the index of the axis whose dimension we infer, or -1 if none
  int inferred_axis_;
  /// @brief the product of the "constant" output dimensions
  int constant_count_;
=======
  int count_;
>>>>>>> BVLC/device-abstraction
};

/**
 * @brief Compute "reductions" -- operations that return a scalar output Blob
 *        for an input Blob of arbitrary size, such as the sum, absolute sum,
 *        and sum of squares.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class ReductionLayer : public Layer<Dtype> {
 public:
  explicit ReductionLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Reduction"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

<<<<<<< HEAD
 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
>>>>>>> master
=======
  /// sum_multiplier is used to carry out sum using BLAS
>>>>>>> origin/BVLC/parallel
=======
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);

 protected:
  Blob<Dtype> mean_, variance_, temp_;

  // sum_multiplier is just used to carry out sum using blas
>>>>>>> BVLC/device-abstraction
  Blob<Dtype> sum_multiplier_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> origin/BVLC/parallel
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Silence"; }
=======
  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_SILENCE;
  }
>>>>>>> origin/BVLC/parallel
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> origin/BVLC/parallel
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class SoftmaxLayer : public Layer<Dtype> {
 public:
  explicit SoftmaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
      const vector<Blob<Dtype>*>& top);

>>>>>>> device-abstraction
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Softmax"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
>>>>>>> origin/BVLC/parallel
=======
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
>>>>>>> origin/BVLC/parallel
=======
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
>>>>>>> device-abstraction
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  /// scale is an intermediate Blob to hold temporary results.
  Blob<Dtype> scale_;
};

#ifdef USE_CUDNN
/**
 * @brief cuDNN implementation of SoftmaxLayer.
 *        Fallback to SoftmaxLayer for CPU mode.
 */
template <typename Dtype>
class CuDNNSoftmaxLayer : public SoftmaxLayer<Dtype> {
 public:
  explicit CuDNNSoftmaxLayer(const LayerParameter& param)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
>>>>>>> pod/device/blob.hpp
=======
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
>>>>>>> pod/caffe-merge
=======
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
>>>>>>> pod-caffe-pod.hpp-merge
      : SoftmaxLayer<Dtype>(param) {}
>>>>>>> origin/BVLC/parallel
=======
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
>>>>>>> device-abstraction
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual ~CuDNNSoftmaxLayer();

 protected:
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
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
=======
>>>>>>> caffe
>>>>>>> pod/caffe-merge
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> device-abstraction
=======
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
>>>>>>> caffe
>>>>>>> pod/caffe-merge
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  bool handles_setup_;
  cudnnHandle_t             handle_;
  cudnnTensorDescriptor_t bottom_desc_;
  cudnnTensorDescriptor_t top_desc_;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
=======
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
=======
>>>>>>> pod/caffe-merge
=======
=======
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
  cudnnHandle_t             handle_;
  cudnnTensor4dDescriptor_t bottom_desc_;
  cudnnTensor4dDescriptor_t top_desc_;
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> device-abstraction
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
};
#endif

/**
 * @brief Creates a "split" path in the network by copying the bottom Blob
 *        into multiple top Blob%s to be used by multiple consuming layers.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class SplitLayer : public Layer<Dtype> {
 public:
  explicit SplitLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
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
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> device-abstraction
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
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
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> device-abstraction
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
<<<<<<< HEAD
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
>>>>>>> pod-caffe-pod.hpp-merge
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
>>>>>>> pod/caffe-merge
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> origin/BVLC/parallel
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> device-abstraction
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
=======
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  /// @brief the reduction operation performed by the layer
  ReductionParameter_ReductionOp op_;
  /// @brief a scalar coefficient applied to all outputs
  Dtype coeff_;
  /// @brief the index of the first input axis to reduce
  int axis_;
  /// @brief the number of reductions performed
  int num_;
  /// @brief the input size of each reduction
  int dim_;
  /// @brief a helper Blob used for summation (op_ == SUM)
>>>>>>> master
=======
  /// sum_multiplier is used to carry out sum using BLAS
>>>>>>> origin/BVLC/parallel
  Blob<Dtype> sum_multiplier_;
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> origin/BVLC/parallel
 * @brief Ignores bottom blobs while producing no top blobs. (This is useful
 *        to suppress outputs during testing.)
 */
template <typename Dtype>
class SilenceLayer : public Layer<Dtype> {
 public:
  explicit SilenceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}

<<<<<<< HEAD
  virtual inline const char* type() const { return "Silence"; }
=======
  virtual inline LayerParameter_LayerType type() const {
    return LayerParameter_LayerType_SILENCE;
  }
>>>>>>> origin/BVLC/parallel
  virtual inline int MinBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 0; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {}
  // We can't define Forward_gpu here, since STUB_GPU will provide
  // its own definition for CPU_ONLY mode.
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
};

/**
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
>>>>>>> master
=======
>>>>>>> master
=======
>>>>>>> origin/BVLC/parallel
 * @brief Computes the softmax function.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class SoftmaxLayer : public Layer<Dtype> {
 public:
  explicit SoftmaxLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual inline const char* type() const { return "Softmax"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
>>>>>>> pod/device/blob.hpp
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
=======
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
>>>>>>> origin/BVLC/parallel
=======
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
=======
>>>>>>> origin/BVLC/parallel
=======
  int outer_num_;
  int inner_num_;
  int softmax_axis_;
>>>>>>> pod/device/blob.hpp
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  /// sum_multiplier is used to carry out sum using BLAS
  Blob<Dtype> sum_multiplier_;
  /// scale is an intermediate Blob to hold temporary results.
  Blob<Dtype> scale_;
};

#ifdef USE_CUDNN
/**
 * @brief cuDNN implementation of SoftmaxLayer.
 *        Fallback to SoftmaxLayer for CPU mode.
 */
template <typename Dtype>
class CuDNNSoftmaxLayer : public SoftmaxLayer<Dtype> {
 public:
  explicit CuDNNSoftmaxLayer(const LayerParameter& param)
<<<<<<< HEAD
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
<<<<<<< HEAD
<<<<<<< HEAD
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
=======
      : SoftmaxLayer<Dtype>(param) {}
>>>>>>> origin/BVLC/parallel
=======
      : SoftmaxLayer<Dtype>(param), handles_setup_(false) {}
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
>>>>>>> pod/device/blob.hpp
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
<<<<<<< HEAD
>>>>>>> origin/BVLC/parallel
=======
=======
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
     const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

<<<<<<< HEAD
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
  bool handles_setup_;
  cudnnHandle_t             handle_;
  cudnnTensorDescriptor_t bottom_desc_;
  cudnnTensorDescriptor_t top_desc_;
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
  cudnnHandle_t             handle_;
  cudnnTensor4dDescriptor_t bottom_desc_;
  cudnnTensor4dDescriptor_t top_desc_;
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
>>>>>>> pod-caffe-pod.hpp-merge
};
#endif

/**
 * @brief Creates a "split" path in the network by copying the bottom Blob
 *        into multiple top Blob%s to be used by multiple consuming layers.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class SplitLayer : public Layer<Dtype> {
 public:
  explicit SplitLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> pod/device/blob.hpp
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
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void SetUp(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual Dtype Forward(const vector<Blob<Dtype>*>& bottom,
      vector<Blob<Dtype>*>* top);
  virtual void Backward(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, vector<Blob<Dtype>*>* bottom);
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
=======
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> BVLC/master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> master
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> origin/BVLC/parallel
=======
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
>>>>>>> caffe
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> BVLC/device-abstraction

  virtual inline const char* type() const { return "Split"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
=======
>>>>>>> pod/caffe-merge
<<<<<<< HEAD
=======
>>>>>>> pod/caffe-merge
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
=======
=======
=======
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> pod/device/blob.hpp
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
=======
>>>>>>> pod/caffe-merge
<<<<<<< HEAD
=======
>>>>>>> pod/device/blob.hpp
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
=======
=======
>>>>>>> pod/device/blob.hpp
=======
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> pod/device/blob.hpp
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
>>>>>>> origin/BVLC/parallel
=======
>>>>>>> caffe
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
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> device-abstraction
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
>>>>>>> pod-caffe-pod.hpp-merge
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

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
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> BVLC/device-abstraction
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/master
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
=======
>>>>>>> BVLC/master
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> BVLC/master
>>>>>>> pod/caffe-merge
=======
>>>>>>> BVLC/master
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> BVLC/device-abstraction
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/master
<<<<<<< HEAD
>>>>>>> device-abstraction
=======
>>>>>>> BVLC/master
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> BVLC/master
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> BVLC/device-abstraction
<<<<<<< HEAD
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/master
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> BVLC/device-abstraction
  int count_;
};

/**
 * @brief Takes a Blob and slices it along either the num or channel dimension,
 *        outputting multiple sliced Blob results.
 *
 * TODO(dox): thorough documentation for Forward, Backward, and proto params.
 */
template <typename Dtype>
class SliceLayer : public Layer<Dtype> {
 public:
  explicit SliceLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Slice"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int MinTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  int count_;
  int num_slices_;
  int slice_size_;
  int slice_axis_;
  vector<int> slice_point_;
};

/**
 * @brief Copy a Blob along specified dimensions.
 */
template <typename Dtype>
class TileLayer : public Layer<Dtype> {
 public:
  explicit TileLayer(const LayerParameter& param)
      : Layer<Dtype>(param) {}
  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const { return "Tile"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);
  virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top);

  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
  virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

  unsigned int axis_, tiles_, outer_dim_, inner_dim_;
};

}  // namespace caffe

#endif  // CAFFE_COMMON_LAYERS_HPP_
