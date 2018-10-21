cmake_minimum_required(VERSION 3.12)
project(Lab2_TPNumber)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2_TPNumber TPNumber_test/main.cpp TPNumber/TPNumber.cpp TPNumber/TPNumber.h TPNumber_test/TPNumber_test.h)