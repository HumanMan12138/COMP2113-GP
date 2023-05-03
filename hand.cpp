#include "hand.h"

// Constructor initializes head pointer to nullptr.
Hand::Hand() : head(nullptr) {}

// Adds a new card by adding a node to the linked list
void Hand::addCard(const Card& card) {
    CardNode* newNode = new CardNode(card);
    newNode->card = card;
    newNode->next = head;
    head = newNode;
}

// Get the total face value of a hand
int Hand::getValue() const {
    int value = 0;
    int aces = 0;
    CardNode* node = head;
    while (node != nullptr) {
        const Card& card = node->card;
        int cardValue;
        if (card.getRank() == ACE) {  // Aces can have a value of 1 or 11
            aces++;
            cardValue = 11;
        }else if (card.getRank() >= JACK) {  // Face cards have a value of 10
            cardValue = 10;
        } else {  // Other cards have a value equal to their rank + 2
            cardValue = card.getRank() + 2;
        }
        value += cardValue;
        node = node->next;
    }

    // If the hand contains aces and the hand value is greater than 21,
    // treat one or more aces as having a value of 1 instead of 11
    while (value > 21 && aces > 0) {
        value -= 10;
        aces--;
    }
    return value;
}
