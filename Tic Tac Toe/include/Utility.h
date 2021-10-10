    #ifndef UTILITY_H_INCLUDED
    #define UTILITY_H_INCLUDED

    #include <windows.h>
    #include <conio.h>

    //#ifndef UTILITY_H
    //#define UTILITY_H

    #define BLUE 0x01
    #define GREEN 0x02
    #define CYAN 0x03
    #define RED 0x04
    #define Meganta 0x05
    #define YELLOW 0x06
    #define WHITE 0x07
    #define REST 0x07

    namespace Utility
    {
        void gotoxy(short x,short y)
        {
            COORD c = {x, y};
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(handle, c);
        }


        void setColor(WORD color)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
        }

        /*int gety()
        {
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

            GetConsoleScreenBufferInfo(h,&csbi);
            cout<<csbi.dwCursorPosition.X<<","<<csbi.dwCursorPosition.Y<<endl;
            int j = csbi.dwCursorPosition.Y;
            return j;
        }*/

        int creatMenu(string menu[],int size)
        {
            const char KEYUP = 72;
            const char KEYDOWN = 80;
            short x = 0;
            short y = 1;
            int c = 1;

            setColor(32);
            for (int i = 0; i < size; i++)
                {
                        cout << menu[i] << endl;
                }

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
                            if (c < 1)
                                c = 1;

                            y --;
                            if (y < 1)
                                y = 1;

                            gotoxy(x,y);
                            cout << "->";
                            break;
                        }

                    case KEYDOWN:
                        {
                            c++;
                            if (c > size-1)
                                c = size-1;

                            y++;
                            if (y > size-1)
                                y = size-1;
                            gotoxy(x,y);
                            cout << "->";
                            break;
                        }
                    }
                }


            cout << "\n\n\n\n\n\nEntered choice from MENU: " << c;
            setColor(REST);
            return c;

        }
    }

//#endif // UTILITY_H



#endif // UTILITY_H_INCLUDED
