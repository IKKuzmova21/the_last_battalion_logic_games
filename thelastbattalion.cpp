#include <iostream>

using namespace std;

void printHangMan(char hangMan[][20])
{
    system("cls");
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            cout << hangMan[i][j];

        }cout << endl;
    }
}
void updateHangMan(char hangMan[][20], char word[], char letter, int i)
{


    word[i] = letter;


}
int main()
{
    char letter, word[100] = "gay", Replacementword[100];
    for (int i = 0; i < 3; i++)
    {
        Replacementword[i] = '_';
    }
    bool running = true;
    char hangMan[10][20]
    {
        {' ','_', '_', '_', '_', '_', '_', '_', '_','_','_', '_', '_', '_', '_', '_', '_', '_'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '|', '\\', ' ', ' ', ' ',},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', '\\', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    while (running)
    {

        printHangMan(hangMan);
        for (int i = 0; i < 3; i++)
        {
            cout << Replacementword[i];
        }
        cin >> letter;

        for (int j = 0; j < 3; j++)
        {
            if (letter = word[j])
                updateHangMan(hangMan, Replacementword, letter, j);

        }



    }
}

