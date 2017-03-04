//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.h"

Deck::Deck(int cardSize, int cardCount, int numberMax)
{
    // TODO: Implement

    //check for a valid cardSize
    if(cardSize >= 3 && cardSize <= 15) {
        m_cardSize = cardSize;

        //check for a valid number of cards in the deck
        if (cardCount >= 3 && cardCount <= 1000) {
            m_cardCount = cardCount;

            //check for a valid numberMax
            if(numberMax >= (2*cardSize*cardSize) && numberMax <= (4*cardSize*cardSize)) {
                m_maxNum = numberMax;
                //Allocate and construct the deck of cards
                m_cards = new Card *[cardCount];
                for (int i = 0; i < cardCount; i++) m_cards[i] = new Card(cardSize, numberMax);
            }
        }
    }
}

Deck::~Deck()
{
    // TODO: Implement
    //
    if(m_cards) delete[] m_cards;
}

bool Deck::print(std::ostream& out) const
{
    // TODO: Implement
    if(m_cards){
        for(int i = 0; i < m_cardCount; i++) {
            out << "Card #" << (i+1) << std::endl;
            m_cards[i]->print(out);
            out << std::endl;
        }
        return true;
    }
    return false;
}

bool Deck::print(std::ostream& out, int cardIndex) const
{
    // TODO: Implement
    if(m_cards && m_cardCount){
        if(cardIndex >= 0 && cardIndex < m_cardCount) {
            out << "Card #" << (cardIndex+1) << std::endl;
            m_cards[cardIndex]->print(out);
            out << std::endl;
            return true;
        }
    }
    return false;
}



