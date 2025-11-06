#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();
    void displayBoard();
    bool makeMove(int row, int col, char player); // Changed to return bool
    bool checkWin();
    bool checkDraw();
    void switchPlayer();
    char getCurrentPlayer();

private:
    char board[3][3];
    char currentPlayer;
    void initializeBoard();
};

#endif // GAME_H