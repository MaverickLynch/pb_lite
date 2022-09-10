cmake_minimum_required(VERSION 3.23)
project(pb_lite)


set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV Pythonlibs REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(pb_lite main.cpp kernals.h imageHelper.h DoG.h linespace.h matplotlibcpp.h)
target_link_libraries(pb_lite ${OpenCV_LIBS} ${PYTHON_LIBRARIES})
