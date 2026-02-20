#pragma once
#include <opencv2/core/hal/interface.h>

#include <opencv2/core.hpp>
#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>

#include "convolution.hpp"

cv::Mat sobel_y_gray(const cv::Mat& img);
cv::Mat sobel_x_gray(const cv::Mat& img);
cv::Mat sobel_gray(const cv::Mat& img);
