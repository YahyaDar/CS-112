#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_BOARD_SIZE = 15;

class StrategicGame {
private:
    char gameBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    int boardSize;
    bool isBotMode;

public:
    StrategicGame(int _boardSize, bool _isBotMode) : boardSize(_boardSize), isBotMode(_isBotMode) {
        if (boardSize != 9 && boardSize != 15) {
            cout << "Invalid board size. Defaulting to 9x9." << endl;
            boardSize = 9;
        }
        initializeBoard();
    }

    void initializeBoard() {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                gameBoard[i][j] = '.';
            }
        }
    }

    void displayBoard() {
        system("clear");
        // system("cls");
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }

    void showWinScreen() {
        system("clear");
        // system("cls");
        cout << "Congratulations! Game over!" << endl;
    }

    void startGame() {
        while (!checkGameEnd()) {
            displayBoard();
            if (isBotMode) {
                humanMove('O');
                if (!checkGameEnd()) // Check if the game has ended after human move
                    botMove();
            } else {
                cout << "O's move: ";
                humanMove('O');
                if (!checkGameEnd()) // Check if the game has ended after O's move
                    cout << "X's move: ";
                humanMove('X');
            }
        }
        if (checkGameEnd()) {
            showWinScreen();
        }
    }

    bool checkGameEnd() {
        // Check rows and columns for a win
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize - 4; ++j) {
                // Check rows
                if (gameBoard[i][j] != '.' && gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j] == gameBoard[i][j+2] && gameBoard[i][j] == gameBoard[i][j+3] && gameBoard[i][j] == gameBoard[i][j+4]) {
                    return true;
                }
                // Check columns
                if (gameBoard[j][i] != '.' && gameBoard[j][i] == gameBoard[j+1][i] && gameBoard[j][i] == gameBoard[j+2][i] && gameBoard[j][i] == gameBoard[j+3][i] && gameBoard[j][i] == gameBoard[j+4][i]) {
                    return true;
                }
            }
        }
        // Check diagonals for a win
        for (int i = 0; i < boardSize - 4; ++i) {
            for (int j = 0; j < boardSize - 4; ++j) {
                // Check diagonals (top-left to bottom-right)
                if (gameBoard[i][j] != '.' && gameBoard[i][j] == gameBoard[i+1][j+1] && gameBoard[i][j] == gameBoard[i+2][j+2] && gameBoard[i][j] == gameBoard[i+3][j+3] && gameBoard[i][j] == gameBoard[i+4][j+4]) {
                    return true;
                }
                // Check diagonals (bottom-left to top-right)
                if (gameBoard[i+4][j] != '.' && gameBoard[i+4][j] == gameBoard[i+3][j+1] && gameBoard[i+4][j] == gameBoard[i+2][j+2] && gameBoard[i+4][j] == gameBoard[i+1][j+3] && gameBoard[i+4][j] == gameBoard[i][j+4]) {
                    return true;
                }
            }
        }
        return false;
    }

    void botMove() {
        int row, col;
        do {
            row = rand() % boardSize;
            col = rand() % boardSize;
        } while (gameBoard[row][col] != '.'); // Keep generating random moves until an empty spot is found
        gameBoard[row][col] = 'X';
    }

    void humanMove(char symbol) {
        int row, col;
        cout << "Enter row and column (1-indexed): ";
        cin >> row >> col;
        row--;
        col--;
        if (row >= 0 && row < boardSize && col >= 0 && col < boardSize && gameBoard[row][col] == '.') {
            gameBoard[row][col] = symbol;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
};

int main() {
    system("clear"); // clear console for Unix systems
    // system("cls"); // clear console for Windows systems
    int boardSize;
    cout << "Choose board size (9 or 15): ";
    cin >> boardSize;

    bool isBotMode;
    cout << "Choose mode (0 for Human vs Human, 1 for Human vs Bot): ";
    cin >> isBotMode;

    StrategicGame game(boardSize, isBotMode);
    game.startGame();

    return 0;
}
