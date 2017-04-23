cmake_minimum_required(VERSION 3.6)
project(HW7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Dictionary.h KeyValue.h Configuration.h Analyzer.cpp Analyzer.h ResultSet.cpp ResultSet.h)
add_executable(HW7 main.cpp ${SOURCE_FILES})

set(TEST_FILES Testing/KeyValueTester.cpp Testing/KeyValueTester.h Testing/DictionaryTester.cpp Testing/DictionaryTester.h Testing/ConfigurationTester.cpp Testing/ConfigurationTester.h)
add_executable(Test Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})