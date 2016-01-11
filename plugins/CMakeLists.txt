cmake_minimum_required(VERSION 3.3)
project(plugins)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES TestPlugin.cpp TestPlugin.h)
add_executable(plugins ${SOURCE_FILES})