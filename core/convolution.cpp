#include "include/convolution.hpp"

#include <opencv2/core.hpp>
#include <opencv2/core/base.hpp>

cv::Mat convolution(const cv::Mat& img, const cv::Mat& kernel) {
  CV_Assert(img.channels() == 1);
  CV_Assert(kernel.channels() == 1);
  CV_Assert(img.type() == CV_32F);
  CV_Assert(kernel.type() == CV_32F);

  int imgRows = img.rows, imgCols = img.cols;
  int kRows = kernel.rows, kCols = kernel.cols;

  int outRows = imgRows - kRows + 1, outCols = imgCols - kCols + 1;

  cv::Mat convImg(outRows, outCols, CV_32F, cv::Scalar(0));

  for (int i = 0; i < outRows; ++i) {
    for (int j = 0; j < outCols; ++j) {
      float sum = 0.0f;

      for (int r = 0; r < kRows; ++r) {
        for (int c = 0; c < kCols; ++c) {
          float imgVal = img.at<float>(i + r, j + c);
          float kVal = kernel.at<float>(r, c);
          sum += imgVal * kVal;
        }
      }

      convImg.at<float>(i, j) = sum;
    }
  }

  return convImg;
}

cv::Mat convolutionRGB(const cv::Mat& img, const cv::Mat& kernel) {
  CV_Assert(img.channels() == 3);
  CV_Assert(kernel.channels() == 1);
  CV_Assert(img.type() == CV_32FC3);
  CV_Assert(kernel.type() == CV_32F);

  std::vector<cv::Mat> channels;
  cv::split(img, channels);
  std::vector<cv::Mat> outChannels(3);
  for (int i = 0; i < 3; ++i) {
    outChannels[i] = convolution(channels[i], kernel);
  }

  cv::Mat conv;
  cv::merge(outChannels, conv);

  return conv;
}

cv::Mat gray_scale(const cv::Mat& img) {
  CV_Assert(img.channels() == 3);

  std::vector<cv::Mat> channels;
  cv::split(img, channels);

  // NOTE: channels[2]=R, channels[1]=G, channels[0]=B in OpenCV's BGR default
  cv::Mat gray_scale = 0.299 * channels[2] + 0.587 * channels[1] + 0.114 * channels[0];

  gray_scale.convertTo(gray_scale, CV_8U);
  CV_Assert(gray_scale.channels() == 1);

  return gray_scale;
}
