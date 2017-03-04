//
// Created by Justin Fairbourn on 3/3/2017.
//

#include "CardTester.h"
#include <iostream>

void CardTester::testConstructor(){
    std::cout << "Test Suite: CardTester::testConstructor() " << std::endl;

    {
        std::cout << "Test Case 1: Good Constructor" << std::endl;
        //normal values
        Card testCard(5, 90);
        if(testCard.getSize()!=5){
            std::cout << "Error in testCard(5, 90) (size). Got: "
                      << testCard.getSize() << " expected: 5" << std::endl;
            return;
        }
        if(testCard.getMaxNum()!=90){
            std::cout << "Error in testCard(5, 90) (maxNum). Got: "
                      << testCard.getMaxNum() << " expected: 90" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 2: Good Constructor" << std::endl;
        //normal minimum values
        Card testCard(3,18);
        if(testCard.getSize()!=3){
            std::cout << "Error in testCard(3,18) (size). Got: "
                      << testCard.getSize() << " expected: 3" << std::endl;
            return;
        }
        if(testCard.getMaxNum()!=18){
            std::cout << "Error in testCard(3,18) (MaxNum). Got: "
                      << testCard.getSize() << " expected: 18" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 3: Good Constructor" << std::endl;
        //normal maximum values
        Card testCard(15, 900);
        if(testCard.getSize()!=15){
            std::cout << "Error in testCard(15,900) (size). Got: "
                      << testCard.getSize() << " expected: 15" << std::endl;
            return;
        }
        if(testCard.getMaxNum()!=900){
            std::cout << "Error in testCard(15,900) (maxNum). Got: "
                      <<testCard.getMaxNum() << " expected: 900" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 4: Bad Constructor" << std::endl;
        //bad card size
        Card testCard(-5, 50);
        if(testCard.getSize()!=0){
            std::cout << "Error in testCard(-5,50) (size). Got: "
                      << testCard.getSize() << " expected 0" << std::endl;
            return;
        }
        if(testCard.getMaxNum()!=0){
            std::cout << "Error in testCard(-5,50) (maxNum). Got: "
                      << testCard.getMaxNum() << " expected 0" << std::endl;
            return;
        }
    }

    {
        std::cout << "Test Case 5: Bad Constructor" << std::endl;
        //bad maxNum
        Card testCard(10, 150);
        if(testCard.getSize()!=10){
            std::cout << "Error in testCard(10,150) (size). Got: "
                      <<testCard.getSize() << " expected 0" << std::endl;
            return;
        }
        if(testCard.getMaxNum()!=0){
            std::cout << "Error in testCard(10,150) (size). Got: "
                      << testCard.getMaxNum() << " expected 0" << std::endl;

            return;
        }
    }
}