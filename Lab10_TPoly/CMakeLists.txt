cmake_minimum_required(VERSION 3.12)
project(Lab10_TPoly)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab10_TPoly TPoly_test/main.cpp TPoly_test/TPoly_test.cpp TPoly_test/TPoly_test.h TPoly/TPoly.cpp TPoly/TPoly.h TMember/TMember.cpp TMember/TMember.h)