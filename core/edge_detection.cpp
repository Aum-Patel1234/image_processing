#include "include/edge_detection.hpp"

#include <opencv2/core.hpp>

cv::Mat sobel_y(const cv::Mat& img) {
  // CV_Assert(img.channels() == 3);

  cv::Mat img32;
  img.convertTo(img32, CV_32FC3);

  cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);

  return convolutionRGB(img32, kernel);
}

cv::Mat sobel_x(const cv::Mat& img) {
  CV_Assert(img.channels() == 1);

  cv::Mat img32;
  img.convertTo(img32, CV_32F);

  cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);

  // cv::Mat conv = convolutionRGB(img32, kernel);
  cv::Mat conv = convolution(img32, kernel);

  double minVal, maxVal;
  cv::minMaxLoc(conv, &minVal, &maxVal);
  conv = 255.0 * (conv - minVal) / (maxVal - minVal);

  // Convert to 8-bit for Python display
  cv::Mat conv8;
  conv.convertTo(conv8, CV_8U);

  return conv8;
}
