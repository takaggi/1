#ifndef CAFFE_GAN_SOLVER_HPP_
#define CAFFE_GAN_SOLVER_HPP_
#include <boost/function.hpp>
#include <string>
#include <vector>

#include "caffe/solver.hpp"
#include "caffe/net.hpp"
#include "caffe/solver_factory.hpp"
#include "caffe/util/benchmark.hpp"

namespace caffe {

template <typename Dtype> class Solver;


/**
 * @brief Type of a function that returns a Solver Action enumeration.
 */
typedef boost::function<SolverAction::Enum()> ActionCallback;

/**
 * @brief An interface for classes that perform optimization on GAN%s.
 *
 * Consist of two solver for generator and discriminator individually.
 */
template <typename Dtype>
class GANSolver {
 public:
  explicit GANSolver(const SolverParameter& g_param, const SolverParameter& d_param);

  shared_ptr<caffe::Solver<Dtype> > getDiscriminatorSolver() {return d_solver;}
  shared_ptr<caffe::Solver<Dtype> > getGeneratorSolver() {return g_solver;}

  void SetActionFunction(ActionCallback func);

  void Restore(const char* resume_file) {
    // TODO
  }

  void TestAll() {
    // TODO
    LOG_IF(INFO, Caffe::root_solver()) << "GAN Test is not implemented.";
  }

  SolverAction::Enum GetRequestedAction();
  
  void Step(int iters);

  virtual void Solve(const char* resume_file = NULL);

 private:
  shared_ptr<caffe::Solver<Dtype> > g_solver, d_solver;

  int iter_;
  int current_step_;

  vector<Dtype> d_losses_, g_losses_;
  Dtype d_smoothed_loss_, g_smoothed_loss_;

  // True iff a request to stop early was received.
  bool requested_early_exit_;

  // Timing information, handy to tune e.g. nbr of GPUs
  Timer iteration_timer_;
  float iterations_last_;

  DISABLE_COPY_AND_ASSIGN(GANSolver);
};

}  // namespace caffe

#endif  // CAFFE_GAN_SOLVER_HPP_