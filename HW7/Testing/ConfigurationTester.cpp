//
// Created by Justin Fairbourn on 4/22/2017.
//

#include "ConfigurationTester.h"
#include <iostream>

void ConfigurationTester::testConstructor(){
    std::cout << "ConfigurationTester::testConstructor" << std::endl;

    Configuration testConfig;

    if(testConfig.getSize() != 0){
        std::cout << "Error in Configuration(). configs size = "
                  << testConfig.getSize() << " should be 0" << std::endl;
        return;
    }

    if(testConfig.getAllocated() != 10){
        std::cout << "Error in Configuration(). configs allocated = "
                  << testConfig.getAllocated() << " should be 10" << std::endl;
        return;
    }
}

void ConfigurationTester::testGetters(){
    std::cout << "ConfigurationTester::testGetters" << std::endl;

    Configuration testConfig;

    KeyValue<std::string, std::string> testPair1("Test Param 1", "3.78");

    testConfig.addNew(testPair1);

    if(testConfig.getAsString("Test Param 1") != "3.78"){
        std::cout << "Error in getAsString(\"Test Param 1\"). getAsString = "
                  << testConfig.getAsString("Test Param 1") << " should be \"3.78\"" << std::endl;
        return;
    }

    if(testConfig.getAsInt("Test Param 1") != 3){
        std::cout << "Error in getAsInt(\"Test Param 1\"). getAsInt = "
                  << testConfig.getAsInt("Test Param 1") << " should be 3" << std::endl;
        return;
    }

    if(testConfig.getAsDouble("Test Param 1") <= 3.781 && testConfig.getAsDouble("Test Param 1") >= 3.78){
        std::cout << "Error in getAsDouble(\"Test Param 1\"). getAsDouble = "
                  << testConfig.getAsDouble("Test Param 1") << " should be 3.78" << std::endl;
        return;
    }
}