#include <iostream>
#include <cstring>
#include "Headerfiles/Main.h"

using namespace std;

int main()
{
    char playAgain;
    printMenu();
    system("pause");
    system("cls");
    runGame();

    while (true)
    {
        
        cin >> playAgain;
        if (playAgain == 'Y' || playAgain == 'y')
        {
            runGame();
        }
        else if (playAgain == 'N' || playAgain == 'n')
        {
            system("cls");
            printMenu();
           
            cout << "            Thank you for playing!" << endl;
            cout << "                 Score: " << points << endl;
            break;
        }
    }
}