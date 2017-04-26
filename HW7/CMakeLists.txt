cmake_minimum_required(VERSION 3.6)
project(HW7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Dictionary.h KeyValue.h Configuration.h Analyzer.h ResultSet.cpp ResultSet.h Configuration.cpp ITAK.cpp ITAK.h DenialOfServiceAnalyzer.cpp DenialOfServiceAnalyzer.h PortScanAnalyzer.cpp PortScanAnalyzer.h Utils.cpp Utils.h)
add_executable(HW7 main.cpp ${SOURCE_FILES})

set(TEST_FILES Testing/KeyValueTester.cpp Testing/KeyValueTester.h Testing/DictionaryTester.cpp Testing/DictionaryTester.h Testing/ConfigurationTester.cpp Testing/ConfigurationTester.h Testing/DenialOfServiceAnalyzerTester.cpp Testing/DenialOfServiceAnalyzerTester.h)
add_executable(Test Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})