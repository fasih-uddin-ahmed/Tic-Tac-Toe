#include <Board.h>

#ifndef GAME_H
#define GAME_H


class Game
{
private:
    Board t;
    bool result;
    char playerChars[2] = {'X','O'};
    int currentPlayer = 0;
    int p1Turns = 0;
    int p2Turns = 0;
    int exit = 0;

public:
    Game();
    ~Game();
    void start();
    void instructions();
    void help();
};

#endif // GAME_H
