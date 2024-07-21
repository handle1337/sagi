cmake_minimum_required(VERSION 3.5.0)
project(sagi VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

add_executable(sagi main.cpp)

include(CTest)
enable_testing()

