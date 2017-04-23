//
// Created by Justin Fairbourn on 4/21/2017.
//

#include "DictionaryTester.h"
#include "KeyValueTester.h"
#include "ConfigurationTester.h"

int main(){
    KeyValueTester::testConstructors();

    DictionaryTester::testConstructors();
    DictionaryTester::testAddAndGrow();
    DictionaryTester::testGetByKey();
    DictionaryTester::testRemoveMethods();

    ConfigurationTester::testConstructor();
    ConfigurationTester::testGetters();
}