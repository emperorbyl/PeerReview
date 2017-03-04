//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include "Card.h"

// TODO: Extend this definition as you see fit

class Deck {
private:
    Card** m_cards = nullptr;
    int m_cardCount = 0;
    int m_cardSize = 0;
    int m_maxNum = 0;

public:
    Deck(int cardSize, int cardCount, int numberMax);
    ~Deck();

    int getCardCount() const {return m_cardCount;}
    int getCardSize() const {return m_cardSize;}
    int getMaxNum() const {return m_maxNum;}

    bool print(std::ostream& out) const;
    bool print(std::ostream& out, int cardIndex) const;
};

#endif //BINGO_DECK_H
