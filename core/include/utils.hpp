#pragma once

#include <opencv2/core/mat.hpp>

cv::Mat normalize_to_U8(const cv::Mat& conv);
cv::Mat normalize_to_U8(cv::Mat&& conv);
cv::Mat gray_scale(const cv::Mat& img);
