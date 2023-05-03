#include <thread>
#include <chrono>
#include <iostream>
#include <iomanip>
#include "game.h"

// This function calculates the amount of padding needed for a given card string to align with the table layout.
int calculatePadding(const std::string &cardString) {
    return 24 - cardString.length();
}

int blackJack(int initialMoney) {
    int playerMoney = initialMoney;
    bool continueGame = false;
    do {
        // Prompt the user to enter a valid bet and update the player's money
        int bet;
        std::cout << "You have " << playerMoney << " coins. Please enter your bet: ";
        std::cin >> bet;
        while (bet <= 0 || bet > playerMoney) {
            std::cout << "Invalid bet. Please enter a bet between 1 and " << playerMoney << ": ";
            std::cin >> bet;
        }
        playerMoney -= bet;
        
        // Reset the player's and dealer's hands, and shuffle the deck
        Hand playerHand = Hand();
        Hand dealerHand = Hand();
        Deck deck;
        deck.shuffle();
        
        // Print table header
        std::cout << "-------------------------------------------------" << std::endl;
        std::cout << "| Dealer                | Player                 |" << std::endl;
        std::cout << "-------------------------------------------------" << std::endl;
        
        // Draw cards for the dealer and the player, add them to their respective hands
        Card playerCard1 = deck.drawCard();
        playerHand.addCard(playerCard1);
        Card playerCard2 = deck.drawCard();
        playerHand.addCard(playerCard2);
        Card dealerCard1 = deck.drawCard();
        dealerHand.addCard(dealerCard1);
        Card dealerHoleCard = deck.drawCard();
        dealerHand.addCard(dealerHoleCard);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "| " << dealerCard1.toString() << std::setw(calculatePadding(dealerCard1.toString())) << "| " << playerCard1.toString() << std::setw(calculatePadding(playerCard1.toString())) << " |" << std::endl;
        std::cout << "| Hole Card" << std::setw(calculatePadding("Hole Card")) << "| " << playerCard2.toString() << std::setw(calculatePadding(playerCard2.toString())) << " |" << std::endl;
        
        
        while (true) {
            // Prints current hand values and prompts player to hit or stand.
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "-------------------------------------------------" << std::endl;
            std::cout << "| Hand Value: " << std::setw(9) << "??" << " | Hand Value: " << std::setw(10) << playerHand.getValue() << " |" << std::endl;
            std::cout << "-------------------------------------------------" << std::endl;
            std::cout << "Do you want to hit (h) or stand (s)? ";
            char decision;
            std::cin >> decision;
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
            if (decision == 'h') { // Player chooses to hit
                Card playerCard = deck.drawCard();
                playerHand.addCard(playerCard);
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "|                       | " << playerCard.toString() << std::setw(calculatePadding(playerCard.toString())) << " |" << std::endl;
                if (playerHand.getValue() > 21) {
                    std::cout << "Player busts! Dealer wins." << std::endl;
                    break;
                }
            } else if (decision == 's') { // Player chooses to stand
                std::cout << "| " << dealerHoleCard.toString() << std::setw(calculatePadding(dealerHoleCard.toString())) << "| " << std::setw(24) << " |" << std::endl;
                std::cout << "| Hand Value: " << std::setw(9) << dealerHand.getValue() << " | Hand Value: " << std::setw(10) << playerHand.getValue() << " |" << std::endl;
                while (dealerHand.getValue() < playerHand.getValue()) { // The dealer should hit if their hand value is less than the player's
                    Card dealerCard = deck.drawCard();
                    dealerHand.addCard(dealerCard);
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "| " << dealerCard.toString() << std::setw(calculatePadding(dealerCard.toString())) << "| " << std::setw(24) << " |" << std::endl;
                    std::cout << "| Hand Value: " << std::setw(9) << dealerHand.getValue() << " | Hand Value: " << std::setw(10) << playerHand.getValue() << " |" << std::endl;
                }
                if (dealerHand.getValue() > 21) { // Dealer busts
                    std::cout << "Dealer busts! Player wins." << std::endl;
                    playerMoney += 2 * bet;
                    break;
                } else if (dealerHand.getValue() < playerHand.getValue()) { // Player wins
                    std::cout << "Player wins! Player hand value: " << playerHand.getValue() << ", Dealer hand value: " << dealerHand.getValue() << std::endl;
                    playerMoney += 2 * bet;
                    break;
                } else if (dealerHand.getValue() > playerHand.getValue()) { // Dealer wins
                    std::cout << "Dealer wins! Player hand value: " << playerHand.getValue() << ", Dealer hand value: " << dealerHand.getValue() << std::endl;
                    break;
                } else { // Tie
                    std::cout << "It's a tie! Player hand value: " << playerHand.getValue() << ", Dealer hand value: " << dealerHand.getValue() << std::endl;
                    playerMoney += bet;
                    break;
                }
            } else {
                std::cout << "Invalid input. Please enter 'h' or 's'." << std::endl;
            }
        }
        
        // Display the player's current amount of money and check if they are run out of money
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Current money: " << playerMoney << std::endl;
        
        if (playerMoney <= 0) {
            std::cout << "You're out of money. Game over!" << std::endl;
            break;
        }
        
        // Prompt the player to continue the game
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Do you want to continue the game? (y/n): ";
        char continueChoice;
        std::cin >> continueChoice;
        if (continueChoice == 'y' || continueChoice == 'Y') {
            continueGame = true;
        } else {
            continueGame = false;
        }
    } while (continueGame);
    return playerMoney;
}
