cmake_minimum_required(VERSION 3.3)
project(server)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

set(SOURCE_FILES main.cpp IEffect.h Types.h plugin/PluginLoader.cpp plugin/PluginLoader.h)

add_executable(server ${SOURCE_FILES})