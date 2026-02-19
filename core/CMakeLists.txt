set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.14)
project(image_processing)

set(CMAKE_CXX_STANDARD 17)
set(PYBIND11_FINDPYTHON ON)

find_package(Python REQUIRED COMPONENTS Interpreter Development NumPy)
find_package(pybind11 REQUIRED CONFIG)
find_package(OpenCV REQUIRED)

file(GLOB_RECURSE SRC_FILES *.cpp)

pybind11_add_module(image_processing
    ${SRC_FILES}
)

target_include_directories(image_processing PRIVATE
    include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(image_processing PRIVATE
    pybind11::module
    Python::NumPy
    ${OpenCV_LIBS}
)

target_compile_definitions(image_processing PRIVATE VERSION_INFO=0.1.0)
