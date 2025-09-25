#include <iostream>
#include <ctime>
#include <limits>
#include <algorithm>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer, char player);
char checkWinner(char *spaces);
bool checkTie(char *spaces);
void resetBoard(char *spaces);
int minimax(char *spaces, bool isMaximizing, char computer, char player);

int main() {
    srand(static_cast<unsigned int>(time(0))); // ✅ RNG only used if randomizing first turn

    char spaces[9];
    char player = 'X';
    char computer = 'O';
    int playerWins = 0, computerWins = 0, ties = 0;
    bool playAgain = true;

    while (playAgain) {
        resetBoard(spaces);
        bool running = true;

        drawBoard(spaces);

        while (running) {
            playerMove(spaces, player);
            drawBoard(spaces);
            char winner = checkWinner(spaces);
            if (winner == player) {
                std::cout << "🎉 YOU WIN!\n";
                playerWins++;
                break;
            }
            if (winner == computer) {
                std::cout << "😢 YOU LOSE!\n";
                computerWins++;
                break;
            }
            if (checkTie(spaces)) {
                std::cout << "🤝 IT'S A TIE!\n";
                ties++;
                break;
            }

            computerMove(spaces, computer, player);
            drawBoard(spaces);
            winner = checkWinner(spaces);
            if (winner == player) {
                std::cout << "🎉 YOU WIN!\n";
                playerWins++;
                break;
            }
            if (winner == computer) {
                std::cout << "😢 YOU LOSE!\n";
                computerWins++;
                break;
            }
            if (checkTie(spaces)) {
                std::cout << "🤝 IT'S A TIE!\n";
                ties++;
                break;
            }
        }

        std::cout << "\n📊 Scoreboard:\n";
        std::cout << "You: " << playerWins << " | Computer: " << computerWins << " | Ties: " << ties << "\n";

        char choice;
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }

    std::cout << "\nThanks for playing! Final score:\n";
    std::cout << "You: " << playerWins << " | Computer: " << computerWins << " | Ties: " << ties << "\n";
    return 0;
}

void resetBoard(char *spaces) {
    for (int i = 0; i < 9; i++) {
        spaces[i] = ' ';
    }
}

void drawBoard(char *spaces) {
    std::cout << "\033[2J\033[1;1H"; // Clear screen
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char *spaces, char player) {
    int number;
    while (true) {
        std::cout << "Enter a spot to place a marker (1-9): ";
        if (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "❌ Invalid input! Please enter a number.\n";
            continue;
        }
        number--; // Convert to 0-based index

        if (number < 0 || number > 8) {
            std::cout << "❌ Invalid number. Please choose between 1 and 9.\n";
            continue;
        }
        if (spaces[number] != ' ') {
            std::cout << "⚠️ Spot already taken. Try again.\n";
            continue;
        }

        spaces[number] = player;
        break;
    }
}

char checkWinner(char *spaces) {
    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (auto &w : wins) {
        if (spaces[w[0]] != ' ' &&
            spaces[w[0]] == spaces[w[1]] &&
            spaces[w[1]] == spaces[w[2]]) {
            return spaces[w[0]]; // 'X' or 'O'
        }
    }
    return ' ';
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') return false;
    }
    return true;
}

int minimax(char *spaces, bool isMaximizing, char computer, char player) {
    char winner = checkWinner(spaces);
    if (winner == computer) return 10;
    if (winner == player) return -10;
    if (checkTie(spaces)) return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 9; i++) {
            if (spaces[i] == ' ') {
                spaces[i] = computer;
                int score = minimax(spaces, false, computer, player);
                spaces[i] = ' ';
                bestScore = std::max(bestScore, score);
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (spaces[i] == ' ') {
                spaces[i] = player;
                int score = minimax(spaces, true, computer, player);
                spaces[i] = ' ';
                bestScore = std::min(bestScore, score);
            }
        }
        return bestScore;
    }
}

void computerMove(char *spaces, char computer, char player) {
    int bestScore = -1000;
    int move = -1;

    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            spaces[i] = computer;
            int score = minimax(spaces, false, computer, player);
            spaces[i] = ' ';
            if (score > bestScore) {
                bestScore = score;
                move = i;
            }
        }
    }

    if (move != -1) {
        spaces[move] = computer;
    }
}
