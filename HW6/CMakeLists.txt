cmake_minimum_required(VERSION 3.6)
project(HW6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Testing/testMain.cpp Dictionary.cpp Dictionary.h KeyValue.cpp KeyValue.h)
add_executable(HW6 ${SOURCE_FILES})