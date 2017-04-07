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

void DictionaryTester::testGetByKey(){
    std::cout << "DictionaryTester::testGetByMethods" << std::endl;
    {
        Dictionary<int, int> testDictionary(5);

        KeyValue<int, int> pair1(1,6);
        KeyValue<int, int> pair2(2,6);
        KeyValue<int, int> pair3(3,4);
        KeyValue<int, int> pair4(7000,3);

        testDictionary.add(&pair1);
        testDictionary.add(&pair2);
        testDictionary.add(&pair3);
        testDictionary.add(&pair4);

        {
            KeyValue<int, int>* testPair = testDictionary.getByKey(1);

            if(testPair->getValue() != 6){
                std::cout << "Error in testDictionary.getByKey(1): getValue() = "
                          << testPair->getValue() << " should be 6" << std::endl;
                return;
            }
        }

        {
            KeyValue<int, int>* testPair = testDictionary.getByKey(7000);

            if(testPair->getValue() != 3){
                std::cout << "Error in testDictionary.getByKey(7000): getValue() = "
                          << testPair->getValue() << " should be 3" << std::endl;
                return;
            }
        }

        {
            try{
                testDictionary.getByKey(100);
            }catch(char const* e){
                if(e!="KEY NOT FOUND"){
                    std::cout << "Error in testDictionary.getByKey(100): ERROR = "
                              << e << " should be \"KEY NOT FOUND\"" << std::endl;
                    return;
                }
            }
        }

        {
            try{
                testDictionary.getByIndex(-3);
            }catch(char const* e){
                if(e!="INDEX OUT OF RANGE") {
                    std::cout << "Error in testDictionary.getByIndex(-3): ERROR = "
                              << e << " should be \"INDEX OUT OF RANGE\"" << std::endl;
                    return;
                }
            }
        }

        {
            try {
                testDictionary.getByIndex(4);
            } catch (char const *e) {
                if (e != "INDEX OUT OF RANGE") {
                    std::cout << "Error in testDictionary.getByIndex(4): ERROR = "
                              << e << " should be \"INDEX OUT OF RANGE\"" << std::endl;
                    return;
                }
            }
        }
    }
}

void DictionaryTester::testRemoveMethods(){
    std::cout << "DictionaryTester::testRemoveMethods" << std::endl;

    {
        Dictionary<int, int> testDictionary(2);

        KeyValue<int, int> pair1(1,6);
        KeyValue<int, int> pair2(2,6);
        KeyValue<int, int> pair3(3,4);
        KeyValue<int, int> pair4(4,3);


        testDictionary.add(&pair1);
        testDictionary.add(&pair2);
        testDictionary.add(&pair3);
        testDictionary.add(&pair4);

        testDictionary.removeByIndex(2);

        {
            if(testDictionary.getSize() != 3){
                std::cout << "Error in testDictionary.removeByIndex(3): getSize() = "
                          << testDictionary.getSize() << " should be 3" << std::endl;
                return;
            }
        }

        {
            KeyValue<int,int>* testPair = testDictionary.getByIndex(2);

            if(testPair->getValue() != 3 || testPair->getKey() != 4){
                std::cout << "Error in testDictionary.removeByIndex(3): getByIndex(3) = ("
                          << testPair->getKey() << "," << testPair->getValue()
                          << ") should be (4,3)" << std::endl;
                return;
            }
        }

        try{
            testDictionary.removeByIndex(-1);
        }catch(char const* e){
            if(e!="INDEX OUT OF RANGE"){
                std::cout << "Error in testDictionary.removeByIndex(-1): Error = "
                          << e << " should be \"INDEX OUT OF RANGE\"" << std::endl;
                return;
            }
        }


        try{
            testDictionary.removeByIndex(3);
        }catch(char const* e){
            if(e!="INDEX OUT OF RANGE"){
                std::cout << "Error in testDictionary.removeByIndex(3): Error = "
                          << e << " should be \"INDEX OUT OF RANGE\"" << std::endl;
                return;
            }
        }

        testDictionary.removeByKey(2);

        {
            if(testDictionary.getSize() != 2){
                std::cout << "Error in testDictionary.removeByKey(2): getSize() = "
                          << testDictionary.getSize() << " should be 2" << std::endl;
                return;
            }

            KeyValue<int, int>* testPair = testDictionary.getByIndex(1);

            if(testPair->getKey() != 4 || testPair->getValue() != 3){
                std::cout << "Error in testDictionary.removeByKey(2): getByIndex(1) = ("
                          << testPair->getKey() << "," << testPair->getValue()
                          << ") should be (4,3)" << std::endl;
                return;
            }
        }

        try{
            testDictionary.removeByKey(8);
        }catch(char const* e){
            if(e!="KEY NOT FOUND"){
                std::cout << "Error in testDictionary.removeByKey(8): Error = "
                          << e << " should be \"KEY NOT FOUND\"" << std::endl;
                return;
            }
        }
    }
}