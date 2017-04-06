//
// Created by Justin Fairbourn on 4/5/2017.
//

#include "DictionaryTester.h"
#include "KeyValueTester.h"

int main(){
    KeyValueTester::testConstructors();
    DictionaryTester::testConstructors();
    DictionaryTester::testAddAndGrow();
}