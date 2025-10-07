//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//const int BOARD_SIZE = 3;
//const char EMPTY = ' ';
//const char PLAYER1 = 'X';
//const char PLAYER2 = 'O';
//
//class TicTacToe {
//private:
//    char board[BOARD_SIZE][BOARD_SIZE];
//    char currentPlayer;
//    int movesCount;
//
//    void initializeBoard() {
//        for (int i = 0; i < BOARD_SIZE; i++) {
//            for (int j = 0; j < BOARD_SIZE; j++) {
//                board[i][j] = EMPTY;
//            }
//        }
//    }
//
//    void displayBoard() {
//        cout << "\n   1   2   3\n";
//        cout << " +---+---+---+\n";
//        for (int i = 0; i < BOARD_SIZE; i++) {
//            cout << i + 1 << "| ";
//            for (int j = 0; j < BOARD_SIZE; j++) {
//                cout << board[i][j] << " | ";
//            }
//            cout << "\n +---+---+---+\n";
//        }
//        cout << endl;
//    }
//
//    bool isValidMove(int row, int col) {
//        return (row >= 0 && row < BOARD_SIZE &&
//            col >= 0 && col < BOARD_SIZE &&
//            board[row][col] == EMPTY);
//    }
//
//    bool makeMove(int row, int col) {
//        if (!isValidMove(row, col)) {
//            return false;
//        }
//        board[row][col] = currentPlayer;
//        movesCount++;
//        return true;
//    }
//
//    bool checkWinner() {
//        // Check rows
//        for (int i = 0; i < BOARD_SIZE; i++) {
//            if (board[i][0] != EMPTY &&
//                board[i][0] == board[i][1] &&
//                board[i][1] == board[i][2]) {
//                return true;
//            }
//        }
//
//        // Check columns
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            if (board[0][j] != EMPTY &&
//                board[0][j] == board[1][j] &&
//                board[1][j] == board[2][j]) {
//                return true;
//            }
//        }
//
//        // Check diagonals
//        if (board[0][0] != EMPTY &&
//            board[0][0] == board[1][1] &&
//            board[1][1] == board[2][2]) {
//            return true;
//        }
//
//        if (board[0][2] != EMPTY &&
//            board[0][2] == board[1][1] &&
//            board[1][1] == board[2][0]) {
//            return true;
//        }
//
//        return false;
//    }
//
//    bool isBoardFull() {
//        return movesCount == BOARD_SIZE * BOARD_SIZE;
//    }
//
//    void switchPlayer() {
//        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
//    }
//
//    void clearScreen() {
//#ifdef _WIN32
//        system("cls");
//#else
//        system("clear");
//#endif
//    }
//
//    void displayHeader() {
//        cout << "===================================\n";
//        cout << "         TIC-TAC-TOE GAME\n";
//        cout << "===================================\n";
//    }
//
//public:
//    TicTacToe() {
//        initializeBoard();
//        currentPlayer = PLAYER1;
//        movesCount = 0;
//    }
//
//    void playGame() {
//        clearScreen();
//        displayHeader();
//
//        cout << "Player 1: " << PLAYER1 << endl;
//        cout << "Player 2: " << PLAYER2 << endl;
//        cout << "\nHow to play: Enter row and column (1-3)\n";
//
//        while (true) {
//            displayBoard();
//            cout << "Player " << currentPlayer << "'s turn\n";
//
//            int row, col;
//            bool validInput = false;
//
//            // Get valid input
//            while (!validInput) {
//                cout << "Enter row (1-3): ";
//                cin >> row;
//                cout << "Enter column (1-3): ";
//                cin >> col;
//
//                // Convert to 0-based indexing
//                row--;
//                col--;
//
//                if (isValidMove(row, col)) {
//                    validInput = true;
//                }
//                else {
//                    cout << "Invalid move! Please choose an empty cell between 1-3.\n";
//                    // Clear input buffer
//                    cin.clear();
//                    cin.ignore(10000, '\n');
//                }
//            }
//
//            // Make the move
//            makeMove(row, col);
//            clearScreen();
//            displayHeader();
//
//            // Check for winner
//            if (checkWinner()) {
//                displayBoard();
//                cout << "\n Congratulations! Player " << currentPlayer << " wins! \n";
//                break;
//            }
//
//            // Check for draw
//            if (isBoardFull()) {
//                displayBoard();
//                cout << "\n Game drawn! Well played both! \n";
//                break;
//            }
//
//            // Switch to next player
//            switchPlayer();
//        }
//    }
//};
//
//int main() {
//    char playAgain;
//
//    do {
//        TicTacToe game;
//        game.playGame();
//
//        cout << "\nDo you want to play again? (y/n): ";
//        cin >> playAgain;
//
//    } while (playAgain == 'y' || playAgain == 'Y');
//
//    cout << "\nThank you for playing Tic-Tac-Toe!\n";
//    return 0;
//}