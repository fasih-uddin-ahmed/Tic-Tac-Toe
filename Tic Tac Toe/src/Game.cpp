#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::start()
{
    do
    {
again:
        system("cls");
        setColor(32);
        cout << "F1 = Exit\nF2 = Help";

        gotoxy(30,0);
        cout << "******TIC TAC TOE******" ;

        gotoxy(12,2);
        cout << "Player 1 (X) - Turns: "<< p1Turns << "\t\tPlayer 2 (O) - Turns: " << p2Turns;

        cout << "\n\nEnter the position Player " << currentPlayer + 1 << " : ";

        t.drawBoard();
        if (p1Turns == 5)
        {
            cout << "\n==>\aThe game is tie...." << endl;
            goto a;
        }

        exit = t.playerMove(playerChars[currentPlayer]);

        switch(exit)
        {
        case 1:
        {
            gotoxy(0,15);
            cout << "\n==>\aYou exited the game...." << endl;
            return;
        }

        case 2:
        {
            help();
            goto again;
        }

        }

        result=t.checkResult(playerChars[currentPlayer]);

        gotoxy(0,15);
        if (result == true)
            cout << "==>\aPLAYER "<< currentPlayer + 1 << " has won the game...";

        if (currentPlayer == 0)
        {
            currentPlayer++;
            p1Turns++;
        }
        else
        {
            currentPlayer--;
            p2Turns++;
        }

    }
    while(result!=true);
a:
    return;
}

void Game::instructions()
{
    system("cls");
    setColor(23);
    cout << "\t\t\t*****TIC TAC TOE GAME INSTRUCTIONS*****" << endl;
    setColor(REST);
    cout << "\nThe object of Tic Tac Toe is to get three in a row. You play on a three by three game board." << endl;
    cout << "The first player is known as X and the second is O. Players alternate placing Xs and Os on the game board until either" << endl;
    cout << "opponent has three in a row or all nine squares are filled. X always goes first, and in the event that no one has three in a row, the stalemate is called a cat game." << endl;
}

void Game::help()
{
    setColor(31);
    gotoxy(75,4);
    cout << "Help:";
    gotoxy(75,5);
    cout << "Move arrow keys to move on game board";
    gotoxy(75,6);
    cout << "and press Enter to mark your position";
    gotoxy(75,7);
    cout << "Press any key to continue...";
    getch();
    setColor(REST);
}
