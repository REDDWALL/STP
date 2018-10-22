cmake_minimum_required(VERSION 3.12)
project(Lab4_TMemory)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab4_TMemory TMemory_test/main.cpp TMemory_test/TMemory_test.h TMemory/TMemory.h)