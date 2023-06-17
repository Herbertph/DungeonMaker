# DungeonMaker
Versions of my first Game
Boardgame I'm developing and I decided to create a program to help me with testing and balancing. 
Below are the rules of the game. Note that we need some abstraction but overall the game is functional.

Game Name: Yet to be defined

Components:
9 dice
1 Deck of 20 Forest cards
1 Deck of 20 Desert cards
1 Deck of 20 Dungeon cards

Game Preparation:
Each player starts at level 1. The decks of Forest, Desert, and Dungeon are shuffled separately and placed in the middle of the table.
Player's Turn:
On their turn, the player does the following:

Dice Roll: The player rolls a number of dice based on their level (5 for levels 1-3, 7 for levels 4-6, 9 for levels 7 and above). All dice outcomes are revealed.
Reroll Dice: The player has the option to reroll any number of the dice obtained in the first roll, with the exception of the dice showing the Dragon face.

Perform Actions: The player can use the dice outcomes to perform several actions. The available actions depend on the dice outcomes:
 Adventure (Forest, Desert, Dungeon): If the player gets one or more Adventure dice, they choose one of the locations (Forest, Desert, Dungeon) and can draw a card from the corresponding deck, spending the relevant Adventure die. When choosing a location, all other location faces on the player's dice must be discarded.
 Sword: Allows the player to defeat monsters.
 Collection: Allows the player to collect discovered treasures.

Adventure Action Consequences:
Depending on the card drawn, the following events occur:
 Treasure: The player reveals the card on the table and can decide later whether or not to collect the treasure, spending a Collection face.
 Enemy: The player needs to spend Sword faces equal to the monster's level to defeat it. If they don't have enough Swords, the player is defeated and loses all of their yet unused actions. The enemy and the treasure remain in the location and must be defeated before other cards can be drawn there. If the player has enough Swords, they defeat the monster, can continue their actions as described by the defeated monster card, and earn victory points.

If the player survives and has no more Adventure faces, they can spend their Collection faces to collect any treasure discovered during their adventure.

End of Turn and Progression:
At the end of the turn, if the player was successful in their adventure (that is, they survived), they level up.

Objective and End of Game:
The goal is to reach level 10 with the most treasures. The game ends when a player reaches level 10 and all other players have had at least one more play. The winner is the player with the most treasures at the end of the game.
