cmake_minimum_required(VERSION 3.12)
project(Lab3_TComplex)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3_TComplex TComplex_test/main.cpp TComplex/TComplex.cpp TComplex/TComplex.h TComplex_test/TComplex_test.h)