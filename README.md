#COMP2113-GP

Group Members
Hu Manman 3035827926
Ye Xinpeng 3033092307
Hu Yueyue 3036105430
Cheng Yanchao 3035772004
Wang Hanyu 3035977991

Introduction

The game of our groups is basically a challenge game. Players need to challenge various passes to win the game. The background of game is from Nordic Mythology, before the Ragnarök, the twilight that Gods will fight against each other and most of them were going to die. Our main character, Tarnished, who is banished in the dungeon under the world tree, is going to challenge the spirits left by gods and demigods to get back his freedom. 
There are a main game and several sub-games that characters will play. 
Firstly, Battleship is known worldwide as a pencil and paper game which dates from World War I. It was published by various companies as a pad-and-pencil game in the 1930s and was released as a plastic board game by Milton Bradley in 1967. The game has spawned electronic versions, video games, smart device apps and a film. We makes a similar game and name it by Battleplane.
Battleplane is played on 10 * 10 board on which the fleet of planes are settled. It is a strategy type guessing game for one player. There are three planes fixed on the board randomly, which do not overlap.(Warmly reminder: They might be really close to each other.)
The player will continuously be asked to call 'shots' by inputting the coordinate of the point they would like to fire at. The locations of the fleets are concealed from the player. Please note that player will be provided only 25 bullets! You will lose if you used up all the bullets.
After shooting, results will be printed out for the player. There will be one or more of these below:

•	Nothing but air: 'You missed!'
•	Some other part of one plane was hit: 'You hit the body!'
•	The head of one plane was shot down:
•	'Good Job! You shot down the plane! There are 2 planes left!'
•	'Great!! You shot down another plane!! There is only 1 plane left!!'
•	'Congratulations!! No plane left, You win!!'

Our objective is to find all the heads of the planes and shoot them down. Once the players have destroyed the fleet, they win that level! There are four directions of the plane.

Secondly, the game Casino, will simulate two betting strategies: Martingale and d'Alembert. This game includes three functions that allow you to choose which betting strategy to simulate.
The first function, called "casino", allows you to choose between the Martingale and d'Alembert betting strategies. The Martingale strategy is a popular betting system that requires you to double your bet after every loss until you win. The idea is that when you do win, you will recover all of your losses and make a profit equal to your original bet. The d'Alembert strategy, on the other hand, is a more conservative betting system that requires you to increase your bet by one unit after every loss and decrease it by one unit after every win.
The second function, "Martingale", simulates the Martingale betting strategy. It takes your starting capital as input and simulates the strategy until either you reach a predetermined profit or you run out of capital. 
The third function, "dAlembert", simulates the d'Alembert betting strategy. It takes your current balance as input and simulates the strategy until either you reach a predetermined profit or you run out of balance.
Overall, in this game you can earn money to purchase tools which will help you in later games, but risks also lies here, you may lost all your money and have nothing to rely on in the rest of the game.

Thirdly, in the game Riddle, You will read the riddle questions and give one word answer. There are five questions in total. If you get one correct answer, 100 points will be awarded, and you need 300 points to win the game. When you encounter problems to get a correct answer, you can spend 100 coins to get a hint from Verthandi. The coins are from the money you earned.

Lastly, the game Blackjack obtains the fundamental principle of the game remains unchanged from that of the standard version of Blackjack.
For your reference, the rules of blackjack obtained from an online search are as follows:
In Blackjack, each player is dealt two cards, and the dealer is dealt one card face up and one card face down. The cards are valued as follows: numbered cards are worth their face value, face cards (Jack, Queen, and King) are worth 10, and an Ace can be worth either 1 or 11.
After the initial deal, players have the option to "hit" (receive additional cards) or "stand" (keep their current hand). The goal is to have a hand value of 21 or as close to 21 as possible without going over. If a player's hand exceeds 21, they lose (known as "busting").
Once all players have finished their turn, the dealer reveals their face-down card and must hit until they have a hand value of 17 or higher. If the dealer busts, all remaining players win. If the dealer does not bust, the player with the highest hand value that doesn't exceed 21 wins.
The following the format for the game's interaction, which outlines the output that the program will provide at each step and the input that is expected from you.
Initially, the game will display your current available funds and prompt you to choose the desired betting amount.
Sample output:
You have 1000 coins. Please enter your bet:
Suppose that we wish to place a wager of 500 coins.
Sample input:
500
Once the bet is placed, the game proceeds to shuffle the deck of cards and deal two cards to both the dealer and the player.

Features and Coding Requirements

Firstly, the main game implements the second and fourth coding requirements. Firstly, it employs the structure Infor to store information of main character, for instance, which pass the main character is in, how much money he holds. During the process of game, players could choose to Save, Continue, or Exit in specific pass slots. Secondly, the main game output the scripts return by input/output text files. Also the structure Infor also store itself by inputting and outputting from the file.

Secondly, Battleship satisfy the first coding requirement. It generates random directions of the heads planes point to and random locations of planes. There are also functions programmed to check if there are any random planes positioned out of the maps and the conditions that several planes are overlapped.

Thirdly, Casino also satisfies the first coding requirement. The head and tail of coin is randomly generated to decide the win or lose of the game. 
Fourthly, Riddle implements the first and fourth requirements. Riddle will randomly generates five riddle questions from its database. What’s more, riddle will input from its files to read the questions and answer for players.
Lastly, Blackjack satisfies the first, second, and third requirement. 1) Generation of random game sets or events. At the start of the game, a deck of cards stored as a vector is shuffled randomly to create a new game set. 2) To keep track of game status, a struct is used to store information about each card, while a vector stores the deck of cards, and a linked list stores the hand cards. 3) The use of linked lists for storing hand cards requires dynamic memory management.

Extensional Libraries
There are no non-standard libraries in C/C++ be used in our games.

Compilation and execution functions
Due to the presence of our makefile, players could simply enter make under linux environments to compile games. 
In the start of the game, players could choose to load the last game or start a new game. By pressing the key “Enter”, the scripts would be outputted and game would proceed.
