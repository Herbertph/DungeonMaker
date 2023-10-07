# DungeonMaker

Welcome to DungeonMaker - a digital implementation of a dice-rolling board game where adventures are created and played out by exploring mystical lands, seeking treasures, and battling monsters. This repository is designed to assist with testing and balancing the gameplay of DungeonMaker.

## Game Overview

DungeonMaker invites players into a fantastical world of adventure and peril. Throughout the game, players will venture through various landscapes including treacherous Forests, arid Deserts, and perilous Dungeons. These settings present opportunities to uncover treasures and engage in battles with monstrous entities.

## Components

- 9 Dice
- 1 Deck of 20 Forest cards
- 1 Deck of 20 Desert cards
- 1 Deck of 20 Dungeon cards

## Game Preparation

- Each player begins at level 1.
- Decks of Forest, Desert, and Dungeon cards are shuffled separately and placed center-table.

## Gameplay

Player’s turns are organized in the following sequence:

### 1. Dice Roll

- Players roll a specific number of dice depending on their level:
  - 5 for levels 1-3
  - 7 for levels 4-6
  - 9 for levels 7 and above
- All dice outcomes are revealed upon rolling.

### 2. Reroll Dice

- Players may reroll any number of dice from the first roll, excluding those that reveal the Dragon face.

### 3. Perform Actions

- Players use dice outcomes to perform various actions, with available actions dependent upon the dice outcomes:
  - **Adventure (Forest, Desert, Dungeon):** Players use Adventure dice to draw a card from a chosen location (Forest, Desert, Dungeon). After selecting a location, all other location faces on the dice are discarded.
  - **Sword:** Players can defeat monsters.
  - **Collection:** Players can gather discovered treasures.
    
### Adventure Action Consequences

Upon drawing a card, several events can occur:

- **Treasure:** The card is revealed, and players may choose to collect the treasure later by using a Collection face.
- **Enemy:** Players must expend Sword faces equal to the monster's level to defeat it. If there are insufficient Swords, the player is defeated, losing all unused actions. The enemy and treasure remain in the location and must be defeated before drawing other cards from it. If the player has enough Swords, they defeat the monster, execute actions as directed by the defeated monster card, and earn victory points.

Should players survive and have no more Adventure faces, they may use Collection faces to gather any treasures found during their adventure.

## End of Turn and Progression

- If the player successfully navigates their adventure (i.e., they survive), they level up.

## Objective and End of Game

- The primary goal is to reach level 10 while collecting as many treasures as possible.
- The game ends when a player reaches level 10, and all other players have had at least one additional turn.
- The winner is the player with the most treasures at the end of the game.
