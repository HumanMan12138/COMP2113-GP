#include "deck.h"
#include <thread>
#include <chrono>
#include <iostream>

Deck::Deck() {
    // Initialize the cards vector with all possible combinations of Suit and Rank
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < RANKS_SIZE; ++rank) {
            cards.push_back(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
        }
    }
}

void Deck::shuffle() {
    // Perform Fisher-Yates shuffle to randomize the order of cards in the deck
    std::srand(std::time(0));
    for (int i = cards.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(cards[i], cards[j]);
    }
    std::cout << "Shuffling..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

Card Deck::drawCard() {
    // Get the top card from the deck
    Card drawn = cards.back();
    cards.pop_back();
    return drawn;
}
