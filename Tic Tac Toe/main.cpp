#include <Game.h>

int main()
{
    ShowConsoleCursor(false);
    int choice;
    string menuList[7] = {"\t\t\t*****TIC TAC TOE GAME MENU*****",
                          "  1.Start New Game","  2.Instructions",
                          "  3.Exit"
                         };
    do
    {
        system("cls");
        Game* temp = new Game;
        choice = creatMenu(menuList,4);

        switch(choice)
        {
        case 1:
        {
            temp->start();
            cout << "\n\nPress any key to continue...";
            getch();
            delete temp;
            break;
        }

        case 2:
        {
            temp->instructions();
            cout << "\nPress any key to continue...";
            getch();
            break;
        }

        case 3:
        {
            return 0;
            break;
        }

        default:
        {
            cout << "\nINVALID INPUT!" << endl;
            cout << "\nPress any key to continue...";
            getch();
            break;
        }
        }
    }
    while(true);
    ShowConsoleCursor(true);
    return 0;
}
