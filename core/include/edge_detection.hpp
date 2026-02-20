#pragma once
#include <opencv2/core/hal/interface.h>

#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>

#include "convolution.hpp"

cv::Mat normalize_to_U8(cv::Mat& conv);

cv::Mat sobel_y_gray(const cv::Mat& img);
cv::Mat sobel_x_gray(const cv::Mat& img);
cv::Mat sobel_y_RGB(const cv::Mat& img);
cv::Mat sobel_x_RGB(const cv::Mat& img);
