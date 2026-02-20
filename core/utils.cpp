#include "include/utils.hpp"

#include <opencv2/core.hpp>

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

cv::Mat normalize_to_U8(const cv::Mat& conv) {
  CV_Assert(conv.type() == CV_32F || conv.type() == CV_32FC3);

  cv::Mat conv8;
  if (conv.channels() == 1) {
    double minVal, maxVal;
    cv::minMaxLoc(conv, &minVal, &maxVal);
    cv::Mat norm = 255.0 * (conv - minVal) / (maxVal - minVal);
    norm.convertTo(conv8, CV_8U);
  } else if (conv.channels() == 3) {
    std::vector<cv::Mat> chans(3), chans8(3);
    cv::split(conv, chans);

    for (int i = 0; i < 3; ++i) {
      double minVal, maxVal;
      cv::minMaxLoc(chans[i], &minVal, &maxVal);
      chans[i] = 255.0 * (chans[i] - minVal) / (maxVal - minVal);
      chans[i].convertTo(chans8[i], CV_8U);
    }
    cv::merge(chans8, conv8);
  }
  return conv8;
}

cv::Mat normalize_to_U8(cv::Mat&& conv) { return normalize_to_U8(static_cast<const cv::Mat&>(conv)); }
