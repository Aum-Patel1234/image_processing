#include <pybind11/pybind11.h>
#include <stdio.h>

#include <opencv2/opencv.hpp>
namespace py = pybind11;

int add(int a, int b) { return a + b; }

void show_image(const std::string& path) {
  cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);

  if (image.empty()) {
    throw std::runtime_error("No image data");
  }

  cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Display Image", image);
  cv::waitKey(0);
}

PYBIND11_MODULE(image_processing, m) {
  m.doc() = "Image processing module";

  m.def("add", &add, "Add two integers");
  m.def("show_image", &show_image, "Display image using OpenCV");
}
