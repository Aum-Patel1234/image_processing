#include "include/edge_detection.hpp"

#include "include/utils.hpp"

// NOTE:
// The Sobel Y kernel, also known as the vertical gradient kernel, highlights horizontal edges. It works by calculating
// the difference between pixels on the top and bottom sides of the center pixel.
// Function: Detects edges where intensity changes vertically (horizontal lines).
cv::Mat sobel_y_gray(const cv::Mat& img) {
  CV_Assert(img.channels() == 1);
  CV_Assert(img.type() == CV_8U);

  cv::Mat img32;
  img.convertTo(img32, CV_32FC3);

  cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
  cv::Mat conv = convolution(img32, kernel);

  return normalize_to_U8(conv);
}

// NOTE:
// The Sobel X kernel, also known as the horizontal gradient kernel, highlights vertical edges. It works by calculating
// the difference between pixels on the left and right sides of the center pixel
// Function:  Detects edges where intensity changes horizontally (vertical lines).
cv::Mat sobel_x_gray(const cv::Mat& img) {
  CV_Assert(img.channels() == 1);
  CV_Assert(img.type() == CV_8U);

  cv::Mat img32;
  img.convertTo(img32, CV_32F);

  cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
  return normalize_to_U8(convolution(img32, kernel));
}

cv::Mat sobel_gray(const cv::Mat& img) {
  CV_Assert(img.channels() == 1);
  CV_Assert(img.type() == CV_8U);

  cv::Mat img32;
  img.convertTo(img32, CV_32F);
  cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
  cv::Mat gx = convolution(img32, kernel);
  kernel = (cv::Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
  cv::Mat gy = convolution(img32, kernel);

  cv::Mat mag;
  cv::magnitude(gx, gy, mag);

  return normalize_to_U8(mag);
}
