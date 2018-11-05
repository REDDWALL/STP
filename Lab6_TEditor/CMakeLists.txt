cmake_minimum_required(VERSION 3.12)
project(Lab6_TEditor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab6_TEditor TEditor_test/main.cpp TEditor/TEditor.cpp TEditor/TEditor.h TEditor_test/TEditor_test.h)