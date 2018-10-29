cmake_minimum_required(VERSION 3.12)
project(Lab5_TProc)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab5_TProc TProc_test/main.cpp TProc/TProc.h TProc_test/TProc_test.h TFrac/TFrac.cpp TFrac/TFrac.h)