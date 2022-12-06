#include <iostream>
#include <cstring>
#include <cstdlib>
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
    char letter, word[100], Replacementword[100];
    int wordLenght;

    cout << "Enter word:" << endl;
    cin.getline(word, 100);
    wordLenght = strlen(word);

    for (int i = 0; i < wordLenght; i++)
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
        cout << "Time to guess the word!" << endl;

        for (int i = 0; i < 3; i++)
        {
            cout << Replacementword[i];
        }
        cin >> letter;

        for (int j = 0; j < 3; j++)
            {
                if (letter == word[j])
                {
                    updateHangMan(hangMan, Replacementword, letter, j);
                }
                else
                    cout << "Wrong guess";
            }

    }
}

