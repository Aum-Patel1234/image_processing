#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

#include <cstddef>
#include <opencv2/opencv.hpp>

#include "include/convolution.hpp"
#include "include/edge_detection.hpp"
namespace py = pybind11;

// testing funcs for CMake
int add(int a, int b) { return a + b; }

// void show_image(const std::string& path) {
//   cv::Mat image = cv::imread(path, cv::IMREAD_COLOR);
//
//   if (image.empty()) {
//     throw std::runtime_error("No image data");
//   }
//
//   cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
//   cv::imshow("Display Image", image);
//   cv::waitKey(0);
// }

py::array mat_to_numpy(const cv::Mat& mat) {
  cv::Mat mat8;
  int channels = mat.channels();
  mat.convertTo(mat8, CV_8U);

  if (channels == 1) {
    // Grayscale
    std::vector<ssize_t> shape = {mat8.rows, mat8.cols};
    std::vector<ssize_t> strides = {static_cast<ssize_t>(mat8.step[0]), static_cast<ssize_t>(mat8.step[1])};

    return py::array_t<uint8_t>(shape, strides, mat8.data).attr("copy")();
  } else if (channels == 3) {
    // RGB
    std::vector<ssize_t> shape = {mat8.rows, mat8.cols, 3};
    std::vector<ssize_t> strides = {static_cast<ssize_t>(mat8.step[0]), static_cast<ssize_t>(mat8.step[1]), 1};

    return py::array_t<uint8_t>(shape, strides, mat8.data).attr("copy")();
  } else {
    throw std::runtime_error("Unsupported number of channels");
  }
}

// Convert numpy array to cv::Mat (makes a copy to own data)
cv::Mat numpy_to_mat(py::array_t<uint8_t> arr) {
  py::buffer_info buf = arr.request();
  int rows = buf.shape[0];
  int cols = buf.shape[1];
  int channels;

  if (buf.ndim == 2)
    channels = 1;
  else if (buf.ndim == 3)
    channels = buf.shape[2];
  else
    throw std::runtime_error("Unsupported array shape");

  int type = (channels == 1) ? CV_8UC1 : CV_8UC3;
  cv::Mat mat(rows, cols, type);
  std::memcpy(mat.data, buf.ptr, rows * cols * channels);

  return mat;
}

PYBIND11_MODULE(image_processing, m) {
  m.doc() = "Image processing module";

  m.def("add", &add, "Add two integers");
  // m.def("show_image", &show_image, "Display image using OpenCV");

  m.def("convolution", &convolution, "Grayscale convolution (CV_32F)");

  m.def("convolution_rgb", &convolutionRGB, "RGB convolution (CV_32FC3)");

  m.def("sobel_x", [](py::array_t<uint8_t> arr) {
    cv::Mat mat = numpy_to_mat(arr);
    cv::Mat result = sobel_x(mat);
    return mat_to_numpy(result);
  });

  m.def("sobel_y", &sobel_y, "Sobel Y edge filter");
}
