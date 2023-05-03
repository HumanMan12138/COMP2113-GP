#include "card.h"

// Constructor for Card object
Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

// Getter method to return the rank of the card
Rank Card::getRank() const {
    return rank;
}

// Getter method to return the suit of the card
Suit Card::getSuit() const {
    return suit;
}

// Method to return a string representation of the card
std::string Card::toString() const {
    // Arrays to hold the names of the ranks and suits
    const std::string rankNames[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    const std::string suitNames[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    // Return a string in the format "Rank of Suit"
    return std::string(rankNames[rank]) + " of " + suitNames[suit];
}
