//
// Created by Justin Fairbourn on 3/3/2017.
//

#include "DeckTester.h"
#include <iostream>

void DeckTester::testConstructor(){
    std::cout << "Test Suite: DeckTester::testConstructor()" << std::endl;

    {
        std::cout << "Test Case 1: Good Constructor" << std::endl;
        //all input is valid
        Deck testDeck(5, 10, 50);
        if(testDeck.getCardSize()!=5){
            std::cout << "Error in testDeck(5, 10, 50) (CardSize) Got: "
                      << testDeck.getCardSize() << " expected: 5" << std::endl;
            return;
        }
        if(testDeck.getCardCount()!=10){
            std::cout << "Error in testDeck(5, 10, 50) (CardCount) Got: "
                      << testDeck.getCardCount() << " expected: 10" << std::endl;
            return;
        }
        if(testDeck.getMaxNum()!=50){
            std::cout << "Error in testDeck(5, 10, 50) (maxNum) Got: "
                      << testDeck.getMaxNum() << " expected: 50" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 2: Good Constructor" << std::endl;
        //all inputs are valid, but are the minimum accepted values
        Deck testDeck(3, 3, 18);
        if(testDeck.getCardSize()!=3){
            std::cout << "Error in testDeck(3,3,18) (CardSize) Got: "
                      <<testDeck.getCardSize() << " expected: 3" << std::endl;
            return;
        }
        if(testDeck.getCardCount()!=3){
            std::cout << "Error in testDeck(3, 3, 18) (CardCount) Got: "
                      << testDeck.getCardCount() << " expected: 3" << std::endl;
            return;
        }
        if(testDeck.getMaxNum()!=18){
            std::cout << "Error in testDeck(3,3,18) (maxNum) Got: "
                      << testDeck.getMaxNum() << "expected: 18" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 3: Good Constructor" << std::endl;
        //all inputs are valid, but are the maximum accepted values
        Deck testDeck(15, 10000, 900);
        if(testDeck.getCardSize()!=15){
            std::cout << "Error in testDeck(15, 10000, 900) (CardSize) Got: "
                      << testDeck.getCardSize() << " expected: 15" << std::endl;
            return;
        }
        if(testDeck.getCardCount()!=10000){
            std::cout << "Error in testDeck(15, 10000, 900) (CardCount) Got: "
                      << testDeck.getCardCount() << " expected: 10000" << std::endl;
            return;
        }
        if(testDeck.getMaxNum()!=900){
            std::cout << "Error in testDeck(15, 10000, 900) (MaxNum) Got: "
                      << testDeck.getMaxNum() << " expected: 900" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 4: Bad Constructor" << std::endl;
        //invalid cardSize
        Deck testDeck(1, 10, 50);
        if(testDeck.getCardSize()!=0){
            std::cout << "Error in testDeck(1, 10, 50) (CardSize) Got: "
                      << testDeck.getCardSize() << " expected: 0" << std::endl;
            return;
        }
        if(testDeck.getCardCount()!=0){
            std::cout << "Error in testDeck(1, 10, 50) (CardCount) Got: "
                      << testDeck.getCardCount() << " expected: 0" << std::endl;
            return;
        }
        if(testDeck.getMaxNum()!=0){
            std::cout << "Error in testDeck(1, 10, 50) (maxNum) Got: "
                      << testDeck.getMaxNum() << " expected: 0" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 5: Bad Constructor" << std::endl;
        //invalid Card Count
        Deck testDeck(5,0,50);
        if(testDeck.getCardSize()!=5){
            std::cout << "Error in testDeck(5,0,50) (CardSize) Got: "
                      << testDeck.getCardSize() << " expected: 5" << std::endl;
            return;
        }
        if(testDeck.getCardCount()!=0){
            std::cout << "Error in testDeck(5,0,50) (CardCount) Got: "
                      <<testDeck.getCardSize() << " expected: 0" << std::endl;
            return;
        }
        if(testDeck.getMaxNum()!=0){
            std::cout << "Error in testDeck(5,0,50) (maxNum) Got: "
                      << testDeck.getMaxNum() << "expected: 0" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 6: Bad Constructor" << std::endl;
        //invalid maxNum
        Deck testDeck(5,15,10);
        if(testDeck.getCardSize()!=5){
            std::cout << "Error in testDeck(5,15,10) (CardSize) Got: "
                      << testDeck.getCardSize() << " expected 5" << std::endl;
            return;
        }
        if(testDeck.getCardCount()!=15){
            std::cout << "Error in testDeck(5,15,10) (CardCount) Got: "
                      << testDeck.getCardCount() << " expected 15" << std::endl;
            return;
        }
        if(testDeck.getMaxNum()!=0){
            std::cout << "Error in testDeck(5,15,10) (CardCount) Got: "
                      << testDeck.getMaxNum() << "expected 0" << std::endl;
            return;
        }
    }
}