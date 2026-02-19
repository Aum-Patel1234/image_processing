#pragma once
#include <opencv2/core/hal/interface.h>

#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>

#include "convolution.hpp"

cv::Mat sobel_y(const cv::Mat& img);
cv::Mat sobel_x(const cv::Mat& img);
