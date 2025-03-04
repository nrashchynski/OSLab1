cmake_minimum_required(VERSION 3.31.5)
project(OSLab1)

set(CMAKE_CXX_STANDARD 98)

add_executable(main src/main.cpp src/employee.h)
add_executable(creator src/creator.cpp src/employee.h)
add_executable(reporter src/reporter.cpp src/employee.h)

enable_testing()

add_executable(test_employee tests/test_employee.cpp src/employee.h)
add_test(NAME EmployeeTest COMMAND test_employee)

add_executable(test_creator tests/test_creator.cpp src/employee.h)
add_test(NAME CreatorTest COMMAND test_creator)

add_executable(test_reporter tests/test_reporter.cpp src/employee.h)
add_test(NAME ReporterTest COMMAND test_reporter)