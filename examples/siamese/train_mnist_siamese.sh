#!/usr/bin/env sh
set -e

# Check if CAFFE_BIN is unset
if [ -z "$CAFFE_BIN" ]; then
  TOOLS=./build/tools
else
  TOOLS=$CAFFE_BIN
fi

$TOOLS/caffe train --solver=examples/siamese/mnist_siamese_solver.prototxt $@
