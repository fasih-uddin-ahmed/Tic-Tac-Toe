#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

using namespace std;


#define BLUE 0x01
#define GREEN 0x02
#define CYAN 0x03
#define RED 0x04
#define Meganta 0x05
#define YELLOW 0x06
#define WHITE 0x07
#define REST 0x07


static void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

static void gotoxy(short x,short y)
{
    COORD c = {x, y};
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, c);
}


static void setColor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}


#define BG_RED 0x40
#define FG_GREEN 0x02
static int creatMenu(string menu[],int size)
{
    const char KEYUP = 72;
    const char KEYDOWN = 80;
    short x,y;
    int c;

    setColor(BG_RED | FG_GREEN);
    for (int i = 0; i < size; i++)
    {
        cout << menu[i] << endl;
    }

up:
    x = 0;
    y = c = 1;

    gotoxy(x,y);
    cout << "->";

    char Arrow = 0;
    while(getch() != '\r')
    {

        Arrow = getch();
        gotoxy(x,y);
        cout << "  ";
        switch(Arrow)
        {
        case KEYUP:
        {
            c--;

            y --;
            if (y < 1)
            {
                c = size-1;
                y = size-1;
            }

            gotoxy(x,y);
            cout << "->";
            break;
        }

        case KEYDOWN:
        {
            c++;

            y++;
            if (y > size-1)
                goto up;

            gotoxy(x,y);
            cout << "->";
            break;
        }
        }
    }


    cout << "\n\n\n\n\nEntered choice from MENU: " << c;
    setColor(REST);
    return c;

}

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    short x,y;
    int arr[7][7] = {{201,205,203,205,203,205,187},

        {186,32,186,32,186,32,186},

        {204,205,206,205,206,205,185},

        {186,32,186,32,186,32,186},

        {204,205,206,205,206,205,185},

        {186,32,186,32,186,32,186},

        {200,205,202,205,202,205,188}
    };

public:
    Board();
    ~Board();
    void drawBoard();
    bool checkResult(char );
    bool checkMove();
    int playerMove(char );
    void shuffleMove();
    void printStar();
};

#endif // BOARD_H
