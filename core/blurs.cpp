#include "include/blurs.hpp"

#include <cmath>
#include <cstddef>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <vector>

#include "edge_detection.hpp"
#include "utils.hpp"

// NOTE: https://en.wikipedia.org/wiki/Gaussian_blur
std::vector<std::vector<float>> makeGaussianKernel(size_t ksize, float sigma) {
  if (sigma <= 0.0) sigma = 0.3 * ((ksize - 1) * 0.5 - 1) + 0.8;
  std::cout << "\nSigma = " << sigma << "\n";

  int half = ksize / 2;
  float sum = 0.0f;

  std::vector<std::vector<float>> kernel(ksize, std::vector<float>(ksize));

  for (int i = -half; i <= half; ++i) {
    for (int j = -half; j <= half; ++j) {
      float val = std::exp(-(i * i + j * j) / (2 * sigma * sigma));
      kernel[i + half][j + half] = val;
      sum += val;
    }
  }
  // normalize
  for (int i = 0; i < ksize; ++i)
    for (int j = 0; j < ksize; ++j) kernel[i][j] /= sum;

  return kernel;
}

cv::Mat gaussian_blur(const cv::Mat& img, size_t ksize, float sigma) {
  auto kvec = makeGaussianKernel(ksize, sigma);

  cv::Mat kernel(ksize, ksize, CV_32F);
  for (int i = 0; i < ksize; ++i)
    for (int j = 0; j < ksize; ++j) kernel.at<float>(i, j) = kvec[i][j];

  cv::Mat img32;
  img.convertTo(img32, img.channels() == 1 ? CV_32F : CV_32FC3);

  cv::Mat blurred = img.channels() == 1 ? convolution(img32, kernel) : convolutionRGB(img32, kernel);

  return normalize_to_U8(blurred);
}

cv::Mat mean_blur(const cv::Mat& img) {
  // CV_Assert(img.channels());

  cv::Mat kernel = (cv::Mat_<float>(3, 3) << 1, 1, 1, 1, 1, 1, 1, 1, 1) / 9.0f;

  switch (img.channels()) {
    case 1: {
      cv::Mat img32;
      img.convertTo(img32, CV_32F);

      return normalize_to_U8(convolution(img32, kernel));
    }
    case 3:
      std::vector<cv::Mat> channels(3), blurred(3);
      cv::split(img, channels);
      for (int i = 0; i < 3; ++i) {
        channels[i].convertTo(channels[i], CV_32F);
        blurred[i] = normalize_to_U8(convolution(channels[i], kernel));
      }

      cv::Mat out;
      cv::merge(blurred, out);
      return out;
  }

  return img.clone();
}
