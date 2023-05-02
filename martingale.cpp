#include <iostream>
#include <cstdlib>
#include <ctime>
#include "head.h"

using namespace std;

int Martingale(int capital);
int dAlembert(int currentBalance);

int Casino(int money)
{
    char choice1;
    cout << "Welcome to the casino!" << endl;
    cout << "Which game do you want to play?" << endl;
    cout << "1. Martingale" << endl;
    cout << "2. d'Alembert" << endl;
    cin >> choice1;
    if (choice1 == '1')
    {
        Martingale(money);
    }
    else if (choice1 == '2')
    {
        dAlembert(money);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
    return money;
}

int Martingale(int capital)
{
    srand(time(NULL)); // seed random number generator with current time

    int startingBet; // the amount of the initial bet
    int currentBet; // the current bet amount
    // capital is the player's current balance,defined above
    int numGames = 0; // the number of games played
    int maxNumGames = 10000; // the maximum number of games to play
    int numWins = 0; // the number of wins
    int numLosses = 0; // the number of losses

    cout << "First bet amount" << endl;
    cin >> startingBet;

    while (startingBet <= 0 || startingBet >= capital)
    {
        cout << "invalid input, please enter again" << endl;
        cin >> startingBet;
    }
    currentBet = startingBet;

    while (numGames < maxNumGames && capital > 0) {
        cout << "Game " << numGames + 1 << endl;
        cout << "Current balance: " << capital << endl;
        cout << "Current bet: " << currentBet << endl;

        // simulate the result of the bet
        bool win = rand() % 2 == 0;

        if (win) {
            capital += currentBet;
            numWins++;
            currentBet = startingBet;
            cout << "You win!" << endl;
        } else {
            capital -= currentBet;
            numLosses++;
            currentBet *= 2;
            cout << "You lose!" << endl;
        }

        cout << "New balance: " << capital << endl;

        char playAgain;
        cout << "Do you want to play again? (y/n) ";
        cin >> playAgain;

        if (playAgain == 'n') {
            break;
        }

        numGames++;
    }

    cout << "Total games played: " << numGames << endl;
    cout << "Total wins: " << numWins << endl;
    cout << "Total losses: " << numLosses << endl;
    cout << "Final balance: " << capital << endl;

    return capital;
}


int dAlembert(int currentBalance)
{
    srand(time(NULL)); // seed random number generator with current time

    int startingBet; // the amount of the initial bet
    int currentBet; // the current bet amount
    int numGames = 0; // the number of games played
    int maxNumGames = 10000; // the maximum number of games to play
    int numWins = 0; // the number of wins
    int numLosses = 0; // the number of losses
    
    cout << "Current balance: " << currentBalance << endl;
    cout << "First bet amount" << endl;
    cin >> startingBet;
    if (startingBet <= 0)
    {
        cout << "Invalid bet amount" << endl;
        return 0;
    }
    if (startingBet > currentBalance)
    {
        cout << "Invalid bet amount" << endl;
        return 0;
    }
    if (startingBet <= currentBalance)
    {
        currentBet = startingBet;
    }

    while (numGames < maxNumGames && currentBalance > 0) {
        cout << "Game " << numGames + 1 << endl;
        cout << "Current balance: " << currentBalance << endl;
        cout << "Current bet: " << currentBet << endl;

        // simulate the result of the bet
        bool win = rand() % 2 == 0;

        if (win) {
            currentBalance += currentBet;
            numWins++;
            currentBet = max(currentBet - 1, 1); // decrease bet by 1 if win
            cout << "You win!" << endl;
        } else {
            currentBalance -= currentBet;
            numLosses++;
            currentBet = currentBet + 1; // increase bet by 1 if loss
            cout << "You lose!" << endl;
        }

        cout << "New balance: " << currentBalance << endl;

        char playAgain;
        cout << "Do you want to play again? (y/n) ";
        cin >> playAgain;

        if (playAgain == 'n' || playAgain =='N') {
            break;
        }

        numGames++;
    }

    cout << "Total games played: " << numGames << endl;
    cout << "Total wins: " << numWins << endl;
    cout << "Total losses: " << numLosses << endl;
    cout << "Final balance: " << currentBalance << endl;

    return currentBalance;
}
