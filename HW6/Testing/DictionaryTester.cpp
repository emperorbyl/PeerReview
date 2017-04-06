//
// Created by Justin Fairbourn on 4/5/2017.
//

#include "DictionaryTester.h"

#include "../Dictionary.h"

#include <iostream>

void DictionaryTester::testConstructors(){
    std::cout << "DictionaryTester::testConstructors" << std::endl;
    {
        //test to see if the default constructor correctly initializes the data members
        Dictionary<int, int> testDictionary;

        if(testDictionary.getSize() != 0){
            std::cout << "Error in testDictionary().getSize(): size = "
                      << testDictionary.getSize() << " should be 0" << std::endl;
            return;
        }

        if(testDictionary.getAllocated() != 10 ){
            std::cout << "Error in testDictionary().getAllocated: allocated = "
                      << testDictionary.getAllocated() << " should be 10" << std::endl;
            return;
        }
    }

    {
        Dictionary<int, int> testDictionary(100);

        if(testDictionary.getAllocated() != 0){
            std::cout << "Error in testDictionary(100).getAllocated: allocated = "
                      << testDictionary.getAllocated() << " should be 100" << std::endl;
            return;
        }
    }

    {
        Dictionary<int, int> testDictionary(100);
        Dictionary<int, int> testCopyDictionary(testDictionary);

        if(testCopyDictionary.getSize() != 0){
            std::cout << "Error in testCopyDictionary(testDictionary).getSize: size = "
                      << testCopyDictionary.getSize() << " should be 0" << std::endl;
            return;
        }

        if(testCopyDictionary.getAllocated() != 100){
            std::cout << "Error in testCopyDictionary(testDictionary).getAllocated: allocated = "
                      << testDictionary.getAllocated() << " should be 100" << std::endl;
            return;
        }
    }
}