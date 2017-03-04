//
// Created by Justin Fairbourn on 2/28/2017.
//

#include "Card.h"
#include <cmath>

/**
 * The Card constructor dynamically allocates the 2D array for the
 * Bingo card that holds the random integers and fills the array
 * @param size The dimension of the card (sizexsize)
 * @param maxNum the maximum allowed number for one bingo card spot
 */
Card::Card(int size, int maxNum){
    //check for valid size
    if(size>=3 && size <=15) {
        m_size = size;
        //check for valid maxNum
        if(maxNum >= 2*pow(size,2) && maxNum <= 4*pow(size,2)) {
            //Allocate the 2D array
            m_maxNum = maxNum;
            m_numbers = new int *[m_size];
            for (int i = 0; i < m_size; i++) m_numbers[i] = new int[m_size];

            //Allocate the Array that keeps track of which numbers have been used.
            //Once a number is used, its index in this array is set to true.
            bool *used = new bool[m_maxNum + 1];
            for (int i = 0; i < m_maxNum + 1; i++) used[i] = false;

            //Pick a random number for each index in the array, only assign it if
            //it's not been used before.
            for (int j = 0; j < m_size; j++) {
                for (int k = 0; k < m_size; k++) {
                    int newNum = rand() % m_maxNum + 1;
                    while (used[newNum]) newNum = rand() % m_maxNum + 1;
                    m_numbers[j][k] = newNum;
                    used[newNum] = true;
                }
            }

            //De-allocate the used array, as it's no longer needed.
            delete[] used;
        }
    }
}

/**
 * Calls the printBorder and printLines in order with the correct parameters
 * @param out the ostream parameter where this is being printed/written
 */
void const Card::print(std::ostream& out){
    int digits;
    (m_maxNum > 99) ? digits = 3 : digits = 2;
    printBorder(out, digits);
    for(int i = 0; i < m_size; i++) printLine(out, digits, i);
}

/**
 * Prints out a border line for the card
 * @param out the ostream parameter where this is being printed/written
 * @param digits the number that determines the width of each 'cell'
 */
void const Card::printBorder(std::ostream& out, int digits){
    out << "+";
    for(int i = 0; i < m_size; i++) {
        for (int j = 0; j < digits+2; j++) out << "-";
        out << "+";
    }
    out << std::endl;
}

/**
 * Prints out the appropriate line in the numbers array formatted correctly
 * @param out the ostream parameter where this is being printed/written
 * @param digits the number that determines the width of each 'cell'
 * @param i the index for the line to print
 */
void const Card::printLine(std::ostream& out, int digits, int row){
    out << "|";
    for(int j = 0; j < m_size; j++) {
        out << " " << std::setw(digits) << std::right << m_numbers[row][j] << " |";
    }
    out << std::endl;
    printBorder(out, digits);
}

/**
 * Destructor that deallocates the arrays
 */
Card::~Card(){
    if(m_size!=0 && m_maxNum!=0) {
        for (int i = 0; i < m_size; i++) delete[] m_numbers[i];
        delete[] m_numbers;
    }
}
