cmake_minimum_required(VERSION 3.3)
project(plugins)



find_package(Eigen3 REQUIRED)
find_package(Qt5Core REQUIRED)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)

set(CMAKE_AUTOMOC ON)

include_directories(${EIGEN3_INCLUDE_DIR}
                    ${Qt5Core_INCLUDE_DIRS})
                    
set(EXAMPLE_SOURCES ExamplePlugin.h ExamplePlugin.cpp)
add_library(example_plugin SHARED ${EXAMPLE_SOURCES})
target_link_libraries(example_plugin Qt5::Core)
add_dependencies(example_plugin server)
install(TARGETS example_plugin DESTINATION plugins)