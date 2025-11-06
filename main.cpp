#include <iostream>
#include "game.h"

using namespace std;

int main() {
    Game game;
    int row, col;
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    string player1Name, player2Name;
    cout << "Enter player 1's name: ";
    getline(cin, player1Name);
    cout << "Enter player 2's name: ";
    getline(cin, player2Name);

    cout << player1Name << " is X,\n" << player2Name << " is O\n";

    game.displayBoard();

    while (!gameOver) {
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column: 0 1 2): ";
        cin >> row >> col;

        // The makeMove function now handles both bounds checking AND checking if the spot is empty.
        if (game.makeMove(row, col, game.getCurrentPlayer())) {
            
            // Only proceed if the move was successful
            game.displayBoard();

            if (game.checkWin()) {
                char winner = game.getCurrentPlayer();
                if (winner == 'X') {
                    cout << player1Name << " wins!\n";
                } else {
                    cout << player2Name << " wins!\n";
                }
                gameOver = true;
            }
            else if (game.checkDraw()) {
                cout << "Game is a draw!\n";
                gameOver = true;
            }
            else {
                game.switchPlayer();
            }
        }
        else {
            // This message now covers both out-of-bounds input AND occupied squares
            cout << "Invalid move, please try again (enter row and column between 0 and 2 for an empty square).\n";
        }
    }

    return 0;
}