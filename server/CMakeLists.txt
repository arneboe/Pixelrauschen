cmake_minimum_required(VERSION 3.3)
project(server)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

set(SOURCE_FILES main.cpp IEffect.h)

add_executable(server ${SOURCE_FILES})