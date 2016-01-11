cmake_minimum_required(VERSION 3.3)
project(plokid)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fPIC -Wno-deprecated-declarations")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#link dynamically against boost
add_definitions(-DBOOST_LOG_DYN_LINK)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(server)
add_subdirectory(plugins)