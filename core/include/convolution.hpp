#include <opencv2/core/hal/interface.h>

#include <opencv2/core.hpp>
#include <opencv2/core/base.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

cv::Mat convolutionRGB(const cv::Mat& img, const cv::Mat& kernel);
cv::Mat convolution(const cv::Mat& img, const cv::Mat& kernel);
