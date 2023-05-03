#ifndef GAME_H
#define GAME_H

#include <string>
#include "hand.h"
#include "deck.h"

int calculatePadding(const std::string &cardString);

int playGame(int initialMoney);

#endif // GAME_H
