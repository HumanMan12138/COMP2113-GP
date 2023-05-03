#ifndef CARD_H
#define CARD_H

#include <string>

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
const int RANKS_SIZE = 13;

struct Card {
    Rank rank;
    Suit suit;

    Card(Rank rank, Suit suit);
    Rank getRank() const;
    Suit getSuit() const;
    std::string toString() const;
};

#endif // CARD_H
