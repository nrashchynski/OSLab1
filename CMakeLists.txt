cmake_minimum_required(VERSION 3.31.5)
project(OSLab1)

set(CMAKE_CXX_STANDARD 98)

add_executable(main src/main.cpp src/employee.h)
add_executable(creator src/creator.cpp src/employee.h)
add_executable(reporter src/reporter.cpp src/employee.h)