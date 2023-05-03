#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

struct Deck {
    Deck();
    void shuffle();
    Card drawCard();
    std::vector<Card> cards;
};

#endif
