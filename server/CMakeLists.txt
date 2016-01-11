cmake_minimum_required(VERSION 3.3)
project(server)

find_package(Eigen3 REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_AUTOMOC ON)

include_directories(${EIGEN3_INCLUDE_DIR}
                    ${Qt5Core_INCLUDE_DIRS})

                    
set(SOURCE_FILES main.cpp
                 plugin/IEffect.h
                 Types.h
                 plugin/PluginLoader.cpp
                 plugin/PluginLoader.h
                 Logging.h)

add_executable(server ${SOURCE_FILES})
target_link_libraries(server Qt5::Core
                             ${Boost_LOG_LIBRARY}
                             ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS server DESTINATION bin)