#ifndef HAND_H
#define HAND_H

#include "card.h"

struct CardNode {
    Card card;
    CardNode* next;
    CardNode(const Card& c) : card(c), next(nullptr) {}
};

struct Hand {
    CardNode* head;
    Hand();
    void addCard(const Card& card);
    int getValue() const;
};

#endif // HAND_H
