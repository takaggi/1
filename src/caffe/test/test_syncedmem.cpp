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
<<<<<<< HEAD
=======
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
=======
>>>>>>> BVLC/device-abstraction
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
>>>>>>> pod-caffe-pod.hpp-merge
<<<<<<< HEAD
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> device-abstraction
=======
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod-caffe-pod.hpp-merge
=======
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> pod/caffe-merge
=======
=======
=======
>>>>>>> BVLC/device-abstraction
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
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
=======
=======
=======
=======
=======
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/device-abstraction
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
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> pod/device/blob.hpp
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> BVLC/device-abstraction
=======
>>>>>>> pod-caffe-pod.hpp-merge
>>>>>>> pod/device/blob.hpp
#ifndef CPU_ONLY
#include <cuda.h>
#include <cuda_runtime.h>
#endif

#include <cstring>
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
>>>>>>> BVLC/device-abstraction
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> pod/caffe-merge
=======
>>>>>>> pod/caffe-merge
=======
=======
>>>>>>> BVLC/device-abstraction
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
>>>>>>> BVLC/device-abstraction
=======
=======
>>>>>>> pod/device/blob.hpp
=======
=======
>>>>>>> pod-caffe-pod.hpp-merge
=======
>>>>>>> BVLC/device-abstraction
=======
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/device-abstraction
=======
=======
>>>>>>> pod/device/blob.hpp
=======
>>>>>>> BVLC/device-abstraction
=======
=======
>>>>>>> pod/device/blob.hpp
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
=======
>>>>>>> master
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
>>>>>>> BVLC/master
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
=======
>>>>>>> pod/device/blob.hpp
>>>>>>> pod-caffe-pod.hpp-merge
#include <vector>

#include "gtest/gtest.h"

#include "caffe/common.hpp"
#include "caffe/device.hpp"
#include "caffe/syncedmem.hpp"
#include "caffe/util/device_alternate.hpp"

#include "caffe/test/test_caffe_main.hpp"

namespace caffe {

class SyncedMemoryTest : public ::testing::Test {};

TEST_F(SyncedMemoryTest, TestInitialization) {
  SyncedMemory mem(10);
  EXPECT_EQ(mem.head(), SyncedMemory::UNINITIALIZED);
  EXPECT_EQ(mem.size(), 10);
  SyncedMemory* p_mem = new SyncedMemory(10 * sizeof(float));
  EXPECT_EQ(p_mem->size(), 10 * sizeof(float));
  delete p_mem;
}

#ifndef CPU_ONLY  // GPU test

TEST_F(SyncedMemoryTest, TestAllocationCPUGPU) {
  SyncedMemory mem(10);
  EXPECT_TRUE(mem.cpu_data());
  EXPECT_TRUE(mem.gpu_data());
  EXPECT_TRUE(mem.mutable_cpu_data());
  EXPECT_TRUE(mem.mutable_gpu_data());
}

#endif

TEST_F(SyncedMemoryTest, TestAllocationCPU) {
  SyncedMemory mem(10);
  EXPECT_TRUE(mem.cpu_data());
  EXPECT_TRUE(mem.mutable_cpu_data());
}

#ifndef CPU_ONLY  // GPU test

TEST_F(SyncedMemoryTest, TestAllocationGPU) {
  SyncedMemory mem(10);
  EXPECT_TRUE(mem.gpu_data());
  EXPECT_TRUE(mem.mutable_gpu_data());
}

#endif

TEST_F(SyncedMemoryTest, TestCPUWrite) {
  SyncedMemory mem(10);
  void* cpu_data = mem.mutable_cpu_data();
  EXPECT_EQ(mem.head(), SyncedMemory::HEAD_AT_CPU);
  GetDevice<int>(Caffe::CPU)->set_void(mem.size(), 1, cpu_data);
  for (int i = 0; i < mem.size(); ++i) {
    EXPECT_EQ((static_cast<char*>(cpu_data))[i], 1);
  }
  // do another round
  cpu_data = mem.mutable_cpu_data();
  EXPECT_EQ(mem.head(), SyncedMemory::HEAD_AT_CPU);
  GetDevice<int>(Caffe::CPU)->set_void(mem.size(), 2, cpu_data);
  for (int i = 0; i < mem.size(); ++i) {
    EXPECT_EQ((static_cast<char*>(cpu_data))[i], 2);
  }
}

#ifndef CPU_ONLY  // GPU test

TEST_F(SyncedMemoryTest, TestGPURead) {
  SyncedMemory mem(10);
  void* cpu_data = mem.mutable_cpu_data();
  EXPECT_EQ(mem.head(), SyncedMemory::HEAD_AT_CPU);
  GetDevice<int>(Caffe::CPU)->set_void(mem.size(), 1, cpu_data);
  const void* gpu_data = mem.gpu_data();
  EXPECT_EQ(mem.head(), SyncedMemory::SYNCED);
  // check if values are the same
  char* recovered_value = new char[10];
  GetDevice<int>(Caffe::GPU)->copy_void(sizeof(char) * 10, gpu_data,
      recovered_value);
  for (int i = 0; i < mem.size(); ++i) {
    EXPECT_EQ((static_cast<char*>(recovered_value))[i], 1);
  }
  // do another round
  cpu_data = mem.mutable_cpu_data();
  EXPECT_EQ(mem.head(), SyncedMemory::HEAD_AT_CPU);
  GetDevice<int>(Caffe::CPU)->set_void(mem.size(), 2, cpu_data);
  for (int i = 0; i < mem.size(); ++i) {
    EXPECT_EQ((static_cast<char*>(cpu_data))[i], 2);
  }
  gpu_data = mem.gpu_data();
  EXPECT_EQ(mem.head(), SyncedMemory::SYNCED);
  // check if values are the same
  GetDevice<int>(Caffe::GPU)->copy_void(sizeof(char) * 10, gpu_data,
      recovered_value);
  for (int i = 0; i < mem.size(); ++i) {
    EXPECT_EQ((static_cast<char*>(recovered_value))[i], 2);
  }
  delete[] recovered_value;
}

TEST_F(SyncedMemoryTest, TestGPUWrite) {
  SyncedMemory mem(10);
  void* gpu_data = mem.mutable_gpu_data();
  EXPECT_EQ(mem.head(), SyncedMemory::HEAD_AT_GPU);
  GetDevice<int>(Caffe::GPU)->set_void(mem.size(), 1, gpu_data);
  const void* cpu_data = mem.cpu_data();
  for (int i = 0; i < mem.size(); ++i) {
    EXPECT_EQ((static_cast<const char*>(cpu_data))[i], 1);
  }
  EXPECT_EQ(mem.head(), SyncedMemory::SYNCED);

  gpu_data = mem.mutable_gpu_data();
  EXPECT_EQ(mem.head(), SyncedMemory::HEAD_AT_GPU);
  GetDevice<int>(Caffe::GPU)->set_void(mem.size(), 2, gpu_data);
  cpu_data = mem.cpu_data();
  for (int i = 0; i < mem.size(); ++i) {
    EXPECT_EQ((static_cast<const char*>(cpu_data))[i], 2);
  }
  EXPECT_EQ(mem.head(), SyncedMemory::SYNCED);
}

#endif

}  // namespace caffe
