#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Card {
    string type;
    int level;
};

struct Player {
    int playerID;
    int level;
    int treasureCount;
    int score;
    bool defeated;
    int treasures;
};

vector<string> rollDice(int playerLevel) {
    vector<string> roll;
    int diceCount;

    if (playerLevel <= 3) {
        diceCount = 5;
    }
    else if (playerLevel <= 6) {
        diceCount = 7;
    }
    else {
        diceCount = 9;
    }

    for (int i = 0; i < diceCount; i++) {
        int diceOutcome = rand() % 6;
        switch (diceOutcome) {
        case 0:
        case 1:
        case 2:
            roll.push_back("Adventure");
            break;
        case 3:
            roll.push_back("Sword");
            break;
        case 4:
            roll.push_back("Collect");
            break;
        case 5:
            roll.push_back("Dragon");
            break;
        }
    }
    return roll;
}

void rerollDice(vector<string>& roll) {
    cout << "Rolled the dice: ";
    for (string face : roll) {
        cout << face << " ";
    }
    cout << endl;

    cout << "Enter the number of the dice or dices that you want to reroll separated by comma (1,2,3). To not reroll any dice, enter 0.\n";
    string input;
    cin >> input;

    if (input != "0") {
        vector<string> diceFaces = { "Sword", "Collect", "Adventure" };
        for (char c : input) {
            if (isdigit(c)) {
                int index = c - '0';
                if (index <= roll.size()) {
                    if (roll[index - 1] == "Dragon") {
                        cout << "You can't reroll the Dragon face." << endl;
                        continue;
                    }
                    int diceOutcome = rand() % 3;
                    roll[index - 1] = diceFaces[diceOutcome];
                }
            }
        }
    }

    cout << "Rerolled the dice: ";
    for (string face : roll) {
        cout << face << " ";
    }
    cout << endl;
}

void handleCardOutcome(Player& player, vector<string>& roll, Card& card, bool& adventureContinues, int& potentialScore) {
    if (card.type == "Monster") {
        int swordCount = std::count(roll.begin(), roll.end(), "Sword");
        if (swordCount >= card.level) {
            // Remove used swords
            for (int i = 0; i < card.level; i++) {
                auto it = std::find(roll.begin(), roll.end(), "Sword");
                if (it != roll.end()) {
                    roll.erase(it);
                }
            }
            cout << "You defeated the monster.\n";
            potentialScore += card.level;
        }
        else {
            cout << "You don't have enough Swords and were defeated.\n";
            player.defeated = true;
            adventureContinues = false;
        }
    }
    else if (card.type == "Treasure") {
        auto it = std::find(roll.begin(), roll.end(), "Collect");
        if (it != roll.end()) {
            // Remove one Collect face
            roll.erase(it);

            player.treasures++;
            cout << "You collected a treasure. Total treasures: " << player.treasures << "\n";
            potentialScore += card.level;
        }
        else {
            cout << "You don't have enough Collect to gather the treasure. The card returns to the deck.\n";
        }
    }
}

Card drawCard(int deckChoice) {
    Card drawnCard;
    int typeOfCard = rand() % 2;

    if (deckChoice == 1) {
        drawnCard.level = 1;
    }
    else if (deckChoice == 2) {
        drawnCard.level = 2;
    }
    else {
        drawnCard.level = 3;
    }

    if (typeOfCard == 0) {
        drawnCard.type = "Treasure";
    }
    else {
        drawnCard.type = "Monster";
    }

    return drawnCard;
}

void playAdventure(Player& player, vector<string>& roll) {
    bool adventureContinues = true;
    int potentialScore = 0;
    int deckChoice;
    cout << "Choose a deck to draw from. Type 1 for Forest, 2 for Desert, 3 for Dungeon.\n";
    cin >> deckChoice;

    while (adventureContinues) {
        if (std::count(roll.begin(), roll.end(), "Adventure") > 0) {
            Card drawnCard = drawCard(deckChoice);
            handleCardOutcome(player, roll, drawnCard, adventureContinues, potentialScore);

            // Remove one Adventure face from roll after a card is drawn
            auto it = std::find(roll.begin(), roll.end(), "Adventure");
            if (it != roll.end()) {
                roll.erase(it);
            }

            // Checks if there are still Adventure faces to continue
            if (std::count(roll.begin(), roll.end(), "Adventure") > 0) {
                if (adventureContinues) {
                    cout << "Would you like to continue the adventure? (Y/N)\n";
                    char continueChoice;
                    cin >> continueChoice;
                    if (continueChoice == 'N' || continueChoice == 'n') {
                        adventureContinues = false;
                    }
                }
            }
            else {
                cout << "You don't have any more Adventure faces available to continue.\n";
                adventureContinues = false;
            }
        }
    }

    if (!player.defeated) {
        player.score += potentialScore;
    }
}

void playTurn(Player& player) {
    player.defeated = false;
    cout << "Player " << player.playerID << "'s turn" << endl;
    vector<string> roll = rollDice(player.level);
    rerollDice(roll);
    playAdventure(player, roll);

    if (!player.defeated) {
        player.level += 1;
        cout << "You survived the adventure!\n";
    }
    cout << "Player's level: " << player.level << ", Score: " << player.score << endl;

    cout << "----------------------------------------------------------" << endl;

}

void displayInstructions() {
    cout << "Welcome to the Adventure Game! Here are the rules:\n\n";
    cout << "- Roll dice according to your level.\n";
    cout << "- You can reroll each dice once, except the ones showing dragons.\n";
    cout << "- Use the adventure dice to draw cards from one of the locations.\n";
    cout << "- Use the collect dice to gather treasures in the locations.\n";
    cout << "- Use the sword dice to defeat the monsters in the locations.\n";
    cout << "- Level up and become more powerful.\n";
    cout << "- Reach level ten and show everyone your spoils and your glorious story!\n\n";
    cout << "Press Enter to play.\n";

    cin.ignore();
}


int main() {
    srand(time(0));
    displayInstructions();
    Player player1 = { 1, 1, 0, 0, false, 0 };
    Player player2 = { 2, 1, 0, 0, false, 0 };

    while (player1.level < 10 && player2.level < 10) {
        playTurn(player1);
        if (player1.level < 10) {
            playTurn(player2);
        }
    }

    // After both players had a chance to reach level 10
    if (player1.level == 10 && player2.level == 10) {
        if (player1.score > player2.score) {
            cout << "Player 1 won with " << player1.score << " points!" << endl;
        }
        else if (player2.score > player1.score) {
            cout << "Player 2 won with " << player2.score << " points!" << endl;
        }
        else {
            cout << "Draw!" << endl;
        }
    }
    else {
        if (player1.level == 10) {
            cout << "Player 1 won!" << endl;
        }
        else {
            cout << "Player 2 won!" << endl;
        }
    }

    return 0;
}
