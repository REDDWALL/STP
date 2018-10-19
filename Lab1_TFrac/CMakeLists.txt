cmake_minimum_required(VERSION 3.12)
project(Lab1_TFrac)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1_TFrac TFrac_test/main.cpp TFrac/TFrac.cpp TFrac/TFrac.h TFrac_test/TFrac_test.h)