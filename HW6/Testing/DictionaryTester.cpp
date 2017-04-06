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

        if(testDictionary.getAllocated() != 100){
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
                      << testCopyDictionary.getAllocated() << " should be 100" << std::endl;
            return;
        }
    }
}

void DictionaryTester::testAddAndGrow(){
    std::cout << "DictionaryTester::testAddAndGrow" << std::endl;
    {
        Dictionary<int, int> testDictionary(2);

        KeyValue<int, int> pair1(1,6);
        KeyValue<int, int> pair2(2,6);
        KeyValue<int, int> pair3(3,4);
        KeyValue<int, int> pair4(4,3);
        KeyValue<int, int> pair5(3,3);

        testDictionary.add(&pair1);
        testDictionary.add(&pair2);
        testDictionary.add(&pair3);
        testDictionary.add(&pair4);

        {
            if(testDictionary.getSize() != 4){
                std::cout << "Error in testDictionary.add: testDictionary.getSize() = "
                          << testDictionary.getSize() << " should be 4" << std::endl;
                return;
            }

            if(testDictionary.getAllocated() != 4){
                std::cout << "Error in testDictionary.add: testDictionary.getAllocated() = "
                          << testDictionary.getAllocated() << " should be 4" << std::endl;
                return;
            }
        }

        {
            KeyValue<int,int>* testPair = testDictionary.getByIndex(0);

            if(testPair->getKey() != 1 || testPair->getValue() != 6){
                std::cout << "Error in testDictionary.add(&pair1): testPair KeyValue = "
                          << testPair->getKey() << "," << testPair->getValue()
                          << " should be 1,6" << std::endl;
                return;
            }
        }

        {
            KeyValue<int,int>* testPair = testDictionary.getByIndex(1);

            if(testPair->getKey() != 2 || testPair->getValue() != 6){
                std::cout << "Error in testDictionary.add(&pair2): testPair KeyValue = "
                          << testPair->getKey() << "," << testPair->getValue()
                          << " should be 2,6" << std::endl;
                return;
            }
        }

        {
            KeyValue<int,int>* testPair = testDictionary.getByIndex(2);

            if(testPair->getKey() != 3 || testPair->getValue() != 4){
                std::cout << "Error in testDictionary.add(&pair3): testPair KeyValue = "
                          << testPair->getKey() << "," << testPair->getValue()
                          << " should be 3,4" << std::endl;
                return;
            }
        }

        {
            KeyValue<int,int>* testPair = testDictionary.getByIndex(3);

            if(testPair->getKey() != 4 || testPair->getValue() != 3){
                std::cout << "Error in testDictionary.add(&pair4): testPair KeyValue = "
                          << testPair->getKey() << "," << testPair->getValue()
                          << " should be 4,3" << std::endl;
                return;
            }
        }

        {
            try{
                testDictionary.add(&pair5);
            }catch (char const* e){
                if(e != "KEY ALREADY IN DICTIONARY"){
                    std::cout << "Error in testDictionary.add(&pair4) (3,3): Error e = "
                              << e << " should be: \"KEY ALREADY IN DICTIONARY\"" << std::endl;
                    return;
                }
            }
        }




    }
}

void DictionaryTester::testGetByMethods(){
    std::cout << "DictionaryTester::testGetByMethods" << sdt::endl;
}