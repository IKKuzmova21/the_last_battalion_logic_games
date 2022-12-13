#include <iostream>
#include "Menu.h"
#include "Body.h"
#include "RunGame.h"
#include "Text.h"
using namespace std;

int main()
{

    char letter;
    printMenu();
    system("pause"); //Pauses the program. The program will countinue when any key is pressed
    system("cls"); //Clears the screen
    runGame(); 

    while (true)
    {

        cin >> letter;
        
        if (letter == 'Y' || letter == 'y')
        {
            runGame();
        }
        else if (letter == 'N' || letter == 'n')
        {
            system("cls"); 
            printMenu();

            cout << "            Thank you for playing!" << endl;
            
            break;
        }
    }
}