cmake_minimum_required(VERSION 3.7)
project(learning_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp bad_pixel_interpolator.cpp parallel_sort.cpp structures.cpp functions.cpp revise.cpp)
add_executable(learning_cpp ${SOURCE_FILES})