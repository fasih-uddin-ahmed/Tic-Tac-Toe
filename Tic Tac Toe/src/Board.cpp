#include "Board.h"

Board::Board()
{
    x=36;
    y=8;
}

Board::~Board()
{

}

void Board::drawBoard()
{
    short k = 6;
    setColor(GREEN);

    for (int i=0; i<7; i++)
    {
        gotoxy(35,++k);
        for (int j=0; j<7; j++)
        {
            cout << (char)arr[i][j] ;
        }
    }
    setColor(REST);
}

void Board::printStar()
{
    gotoxy(x,y);
    cout << "*";
}

bool Board::checkMove()
{
    if(arr[y-7][x-35] != 32 ) return false;

    return true;
}

void Board::shuffleMove()
{
    x++;
    if (x>41)
    {
        x=36;
        y++;
    }
    if (y>13) y=8;
}


int Board::playerMove(char pChar)
{
    const char KEYUP = 72;
    const char KEYLEFT = 75;
    const char KEYRIGHT = 77;
    const char KEYDOWN = 80;
    const char ESC = 59;
    const char HELP = 60;

    while (checkMove() == false) shuffleMove();

    printStar();

    char Arrow = 0;
    while(getch() != '\r')
    {

        Arrow = getch();
        gotoxy(x,y);
        cout << " ";
        switch(Arrow)
        {
        case KEYUP:
        {
            y -= 2;

            if (y < 8)
                y = 12;

            while (checkMove() == false) shuffleMove();

            printStar();
            break;
        }

        case KEYLEFT:
        {
            x -= 2;

            if (x < 35)
                x = 40;

            while (checkMove() == false) shuffleMove();

            printStar();
            break;
        }

        case KEYRIGHT:
        {
            x += 2;

            if (x > 41)
            {
                x = 36;
                y++;
            }

            while (checkMove() == false) shuffleMove();

            printStar();
            break;
        }

        case KEYDOWN:
        {
            y += 2;

            if (y > 12)
                y = 8;

            while (checkMove() == false) shuffleMove();

            printStar();
            break;
        }

        case ESC:
        {
            return 1;
            break;
        }

        case HELP:
        {
            return 2;
            break;
        }
        }
    }

    arr[y-7][x-35] = (int)pChar;
}

bool Board::checkResult(char pChars)
{
    if (arr[1][1] == (int)pChars  && arr[1][1] == arr[1][3] && arr[1][3] == arr[1][5])
        return true;
    else if (arr[3][1] == (int)pChars  && arr[3][1]  == arr[3][3] && arr[3][3] == arr[3][5])
        return true;
    else if (arr[5][1] == (int)pChars  && arr[5][1]  == arr[5][3] && arr[5][3] == arr[5][5])
        return true;
    else if (arr[1][1] == (int)pChars  && arr[1][1]  == arr[3][1] && arr[3][1] == arr[5][1])
        return true;
    else if (arr[1][3] == (int)pChars  && arr[1][3]  == arr[3][3] && arr[3][3] == arr[5][3])
        return true;
    else if (arr[1][5] == (int)pChars  && arr[1][5]  == arr[3][5] && arr[3][5] == arr[5][5])
        return true;
    else if (arr[1][1] == (int)pChars  && arr[1][1]  == arr[3][3] && arr[3][3] == arr[5][5])
        return true;
    else if (arr[1][5] == (int)pChars  && arr[1][5]  == arr[3][3] && arr[3][3] == arr[5][1])
        return true;
    else
        return false;
}

