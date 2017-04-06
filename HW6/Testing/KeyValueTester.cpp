//
// Created by Justin Fairbourn on 4/5/2017.
//

#include "KeyValueTester.h"
#include "../KeyValue.h"
#include <iostream>

void KeyValueTester::testConstructors(){
    std::cout << "KeyValueTester::testConstructors" << std::endl;
    //test a few different primitive types
    {
        KeyValue<int, int> testKeyValue(3,6);

        if(testKeyValue.getKey() != 3){
            std::cout << "Error in testKeyValue(3,6).getKey: key = "
                      << testKeyValue.getKey() << " should be 3" << std::endl;
            return;
        }

        if(testKeyValue.getValue() != 6){
            std::cout << "Error in testKeyValue(3,6).getValue: value = "
                      << testKeyValue.getValue() << " should be 6" << std::endl;
            return;
        }
    }

    {
        KeyValue<std::string, int> testKeyValue("carrots", 7);

        if(testKeyValue.getKey() != "carrots"){
            std::cout << "Error in testKeyValue(\"carrots\", 7).getKey: key = "
                      << testKeyValue.getKey() << " should be \"carrots\"" << std::endl;
            return;
        }

        if(testKeyValue.getValue() != 7){
            std::cout << "Error in testKeyValue(\"carrots\", 7).getValue: value = "
                      << testKeyValue.getValue() << " should be 7" << std::endl;
            return;
        }
    }

    //test Copy Constructor
    {
        KeyValue<int, double> copyTestKeyValue(3, 1.001);
        KeyValue<int, double> testKeyValue(copyTestKeyValue);

        if(testKeyValue.getKey() != 3){
            std::cout << "Error in testKeyValue(3, 1.001).getKey: key = "
                      << testKeyValue.getKey() << " should be 3" << std::endl;
            return;
        }

        if(testKeyValue.getValue() != 1.001){
            std::cout << "error in testKeyValue(3, 1.001).getValue: value = "
                      << testKeyValue.getValue() << "should be 1.001" << std::endl;
            return;
        }
    }
}