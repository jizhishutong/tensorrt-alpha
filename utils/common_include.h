#pragma once
// tensorrt
#include<argsParser.h>
#include<buffers.h>
#include<common.h>
#include<logger.h>
#include<parserOnnxConfig.h>
#include<sampleEngines.h>
#include<NvInfer.h>

// cuda
#include<cuda_runtime.h>
#include<stdio.h>
#include <thrust/sort.h>
//#include <thrust/device_vector.h>
//#include<math.h>
//#include<math_functions.h>
#include<cuda_device_runtime_api.h>
#include<cuda_runtime.h>
#include<cuda_runtime_api.h>
#include<device_launch_parameters.h>
//#include<device_functions.h>
#include<device_atomic_functions.h>

// opencv
#include<opencv2/opencv.hpp>

// cpp std
#include<algorithm>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<chrono>