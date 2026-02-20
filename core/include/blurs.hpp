#pragma once

#include <cstddef>
#include <opencv2/core.hpp>
#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
#include <vector>

cv::Mat gaussian_blur(const cv::Mat& img, size_t ksize, float sigma = 0.0);
cv::Mat mean_blur(const cv::Mat& img);
std::vector<std::vector<float>> makeGaussianKernel(size_t ksize, float sigma = 0.0);
