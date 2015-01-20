#!/bin/bash
# This script must be run with sudo.

set -e

MAKE="make --jobs=$NUM_THREADS"

# Install apt packages where the Ubuntu 12.04 default and ppa works for Caffe

# This ppa is for gflags and glog
add-apt-repository -y ppa:tuleu/precise-backports
apt-get -y update
apt-get install \
    wget git curl nasm libcurl4-openssl-dev \
    python-dev python-numpy \
    libleveldb-dev libsnappy-dev libopencv-dev \
    libboost-all-dev \
    libatlas-dev libatlas-base-dev \
    libhdf5-serial-dev libgflags-dev libgoogle-glog-dev \
    bc

PROTOBUF_URL=https://protobuf.googlecode.com/files/protobuf-2.5.0.tar.gz
PROTOBUF_FILE=/tmp/protobuf-2.5.0.tar.gz
PROTOBUF_DIR=protobuf-2.5.0
curl $PROTOBUF_URL -o $PROTOBUF_FILE
pushd .
cd /tmp
tar xf $PROTOBUF_FILE
cd $PROTOBUF_DIR
./configure
$MAKE
make install
echo "/usr/local/lib" >> /etc/ld.so.conf
ldconfig
protoc --version

# Add a special apt-repository to install CMake 2.8.9 for CMake Caffe build,
# if needed.  By default, Aptitude in Ubuntu 12.04 installs CMake 2.8.7, but
# Caffe requires a minimum CMake version of 2.8.8.
if $WITH_CMAKE; then
  add-apt-repository -y ppa:ubuntu-sdk-team/ppa
  apt-get -y update
  apt-get -y install cmake
fi

# Install CUDA, if needed
if $WITH_CUDA; then
  CUDA_URL=http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1204/x86_64/cuda-repo-ubuntu1204_6.5-14_amd64.deb
  CUDA_FILE=/tmp/cuda_install.deb
  curl $CUDA_URL -o $CUDA_FILE
  dpkg -i $CUDA_FILE
  rm -f $CUDA_FILE
  apt-get -y update
  # Install the minimal CUDA subpackages required to test Caffe build.
  # For a full CUDA installation, add 'cuda' to the list of packages.
  apt-get -y install cuda-core-6-5 cuda-cublas-6-5 cuda-cublas-dev-6-5 cuda-cudart-6-5 cuda-cudart-dev-6-5 cuda-curand-6-5 cuda-curand-dev-6-5
  # Create CUDA symlink at /usr/local/cuda
  # (This would normally be created by the CUDA installer, but we create it
  # manually since we did a partial installation.)
  ln -s /usr/local/cuda-6.5 /usr/local/cuda
fi

# Install LMDB
LMDB_URL=ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/openldap-2.4.39.tgz
LMDB_FILE=/tmp/openldap.tgz
pushd .
curl $LMDB_URL -o $LMDB_FILE
tar -C /tmp -xzvf $LMDB_FILE
cd /tmp/openldap*/libraries/liblmdb/
$MAKE
$MAKE install
popd
rm -f $LMDB_FILE

# Install curlpp
CURLPP_URL=https://curlpp.googlecode.com/files/curlpp-0.7.3.tar.gz
CURLPP_FILE=/tmp/curlpp.tar.gz
CURLPP_DIR=curlpp-0.7.3
curl $CURLPP_URL -o $CURLPP_FILE
pushd .
cd /tmp
tar xf $CURLPP_FILE
pushd .
cd $CURLPP_DIR
./configure
$MAKE
make install
popd
rm -rf $CURLPP_DIR
popd
rm -f $CURLPP_FILE

# Install turbo-jpeg
TURBO_JPEG_URL=http://downloads.sourceforge.net/project/libjpeg-turbo/1.3.1/libjpeg-turbo-1.3.1.tar.gz
TURBO_JPEG_FILE=/tmp/libjpeg-turbo.tar.gz
TURBO_JPEG_DIR=libjpeg-turbo-1.3.1
curl $TURBO_JPEG_URL -o $TURBO_JPEG_FILE -L
pushd .
cd /tmp
tar xf $TURBO_JPEG_FILE
pushd .
cd $TURBO_JPEG_DIR
./configure
$MAKE
make install
popd
rm -rf $TURBO_JPEG_DIR
popd
rm -f $TURBO_JPEG_FILE
echo "/opt/libjpeg-turbo/lib64" >> /etc/ld.so.conf
ldconfig
