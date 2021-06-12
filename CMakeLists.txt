cmake_minimum_required(VERSION 3.16)
project(design_pattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(design_pattern main.cpp)
add_executable(factory factory.cpp)
add_executable(abstractFactory abstractFactory.cpp)