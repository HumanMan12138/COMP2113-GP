COMP2113 Group Project

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
Battleplane is played on 10 * 10 board on which the fleet of planes are settled. It is a strategy type guessing game for one player. There are three planes fixed on the board randomly, which do not overlap.(Warmly reminder ^*^ : They might be really close to each other.)
The player will continuously be asked to call 'shots' by inputting the coordinate of the point they would like to fire at. The locations of the fleets are concealed from the player. *Please note that player will be provided only 25 bullets! You will lose if you used up all the bullets.
After shooting, results will be printed out for the player. There will be one or more of these below:
•	Nothing but air: 'You missed!'
•	Some other part of one plane was hit: 'You hit the body!'
•	The head of one plane was shot down:
•	'Good Job! You shot down the plane! There are 2 planes left!'
•	'Great!! You shot down another plane!! There is only 1 plane left!!'
•	'Congratulations!! No plane left, You win!!'
Our objective is to find all the heads of the planes and shoot them down. Once the players have destroyed the fleet, they win that level! Have a look at the plane from four directions:
  *          +++          +            + 
+++++         +           + +        + + 
  +         +++++        *+++        ++++*
 +++          *           + +        + +
                          +            +

Current money: 500
Do you want to continue the game? (y/n): 
Opting for "yes" would result in the game being restarted with a reshuffle and redealing of the cards, while opting for "no" would cause the game to return to the main game.

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

