cmake_minimum_required(VERSION 3.12)
project(Lab7_TFracEditor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab7_TFracEditor TFracEditor_test/main.cpp TFracEditor/TFracEditor.cpp TFracEditor/TFracEditor.h TFracEditor_test/TFracEditor_test.cpp TFracEditor_test/TFracEditor_test.h)