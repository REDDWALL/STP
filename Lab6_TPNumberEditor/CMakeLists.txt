cmake_minimum_required(VERSION 3.12)
project(Lab6_TPNumberEditor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab6_TEditor TPNumberEditor_test/main.cpp TPNumberEditor/TPNumberEditor.cpp TPNumberEditor/TPNumberEditor.h TPNumberEditor_test/TPNumberEditor_test.h)