#include <iostream>
// board Array 
int board[3][3];
// Cout for instructions
void showInstructions() {
    std::cout << "=================================\n";
    std::cout << "        TIC-TAC-TOE GAME\n";
    std::cout << "=================================\n";
    std::cout << "Instructions:\n";
    std::cout << "1. Player 1 = X, Player 2 = O\n";
    std::cout << "2. Enter row and column (0-2)\n\n";

    std::cout << "Board positions:\n";
    std::cout << " 0,0 | 0,1 | 0,2\n";
    std::cout << "-----+-----+-----\n";
    std::cout << " 1,0 | 1,1 | 1,2\n";
    std::cout << "-----+-----+-----\n";
    std::cout << " 2,0 | 2,1 | 2,2\n\n";

    std::cout << "Press Enter to start...";
    std::cin.ignore();
    std::cin.get();
}
// Display of Board for the players 
void displayBoard() {
    std::cout << "\n";
    for (int i = 0; i < 3; i++) {
        std::cout << " ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1)
                std::cout << "X";
            else if (board[i][j] == 2)
                std::cout << "O";
            else
                std::cout << " ";
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}
// 
bool checkWin(int player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == 0)
                return false;
    return true;
}

void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
}

// rechecking the input function 
void getValidMove(int &row, int &col) {
    while (true) {
        std::cout << "Enter row and column (0-2): ";

        if (!(std::cin >> row >> col)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter two numbers like: 1 2\n";
            continue;
        }

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            std::cout << "Out of range. Use numbers between 0 and 2.\n";
            continue;
        }

        if (board[row][col] != 0) {
            std::cout << "That spot is already taken. Try again.\n";
            continue;
        }

        break;
    }
}

void playGame() {
    int currentPlayer = 1;
    int row, col;
    bool gameOver = false;

    while (!gameOver) {
        displayBoard();

        std::cout << "Player " << (currentPlayer == 1 ? "X" : "O") << "'s turn\n";
        getValidMove(row, col);  // ✅ replaced input logic

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer)) {
            displayBoard();
            std::cout << "Player " << (currentPlayer == 1 ? "X" : "O") << " wins!\n";
            gameOver = true;
        } else if (isBoardFull()) {
            displayBoard();
            std::cout << "It's a draw!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }
}

int main() {
    showInstructions();

    char playAgain;
    do {
        resetBoard();
        playGame();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!\n";
}
