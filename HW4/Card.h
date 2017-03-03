//
// Created by Justin Fairbourn on 2/28/2017.
//

#ifndef BINGO_CARD_H
#define BINGO_CARD_H

#include <ostream>
#include <iomanip>

class Card {
private:
    int m_size;
    int** m_numbers;
    int m_maxNum;

public:
    Card(int size, int maxNum);
    ~Card();

    void const print(std::ostream& out);
    void const printBorder(std::ostream& out, int digits);
    void const printLine(std::ostream& out, int digits, int row);
};
#endif //BINGO_CARD_H