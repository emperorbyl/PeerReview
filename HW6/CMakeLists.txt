cmake_minimum_required(VERSION 3.6)
project(HW6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Dictionary.h KeyValue.h)
add_executable(HW6 main.cpp ${SOURCE_FILES})

set(TEST_FILES Testing/KeyValueTester.cpp Testing/KeyValueTester.h Testing/DictionaryTester.cpp Testing/DictionaryTester.h)
add_executable(Test Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})