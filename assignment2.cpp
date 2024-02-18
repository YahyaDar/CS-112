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
        system("cls");
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }

    void showWinScreen() {
        system("clear");
        system("cls");
        cout << "Congratulations! Game over!" << endl;
    }

    void startGame() {
        while (!checkGameEnd()) {
            displayBoard();
            if (isBotMode) {
                humanMove('O');
                botMove();
            } else {
                cout << "O's move: ";
                humanMove('O');
                cout << "X's move: ";
                humanMove('X');
            }
        }
        if (checkGameEnd()) {
            showWinScreen();
        }
    }

    bool checkGameEnd() {
        // Game over conditions
        // (Implementation of game end conditions goes here)
        return false;
    }

    void botMove() {
        // Bot's move logic
        // (Implementation of bot's move goes here)
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
    system("cls"); // clear console for Windows systems
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
