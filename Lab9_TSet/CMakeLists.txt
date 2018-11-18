cmake_minimum_required(VERSION 3.12)
project(Lab9_TSet)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab9_TSet TSet_test/main.cpp TSet_test/TSet_test.cpp TSet_test/TSet_test.h TSet/TSetFirst.h TSet/TSetSecond.h TFrac/TFrac.cpp TFrac/TFrac.h)