#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool checkForCompletion(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '_') return false;
    }
    return true;
}

void printHangMan(char hangMan[][20])
{
    system("cls");
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            cout << hangMan[i][j];
        } cout << endl;
    }
}
void updateHangMan(char hangMan[][20], char word[], char letter, int i)
{
    word[i] = letter;
}
void updateHead(char hangMan[][20], char cheatSheat[])
{
    for (int i = 0; i <= 6; i += 3)
    {
        hangMan[cheatSheat[i]][cheatSheat[i + 1]] = cheatSheat[i + 2];
    }
}
void updateBody(char hangMan[][20], char cheatSheat[])
{
    for (int i = 9; i <= 13; i += 3)
    {
        hangMan[cheatSheat[i]][cheatSheat[i + 1]] = cheatSheat[i + 2];
    }
}
void updateArms(char hangMan[][20], char cheatSheat[])
{
    for (int i = 12; i <= 20; i += 3)
    {
        hangMan[cheatSheat[i]][cheatSheat[i + 1]] = cheatSheat[i + 2];
    }
}
void updateLegs(char hangMan[][20], char cheatSheat[])
{
    for (int i = 15; i <= 24; i += 3)
    {
        hangMan[cheatSheat[i]][cheatSheat[i + 1]] = cheatSheat[i + 2];
    }
}
void updateFinalCross(char hangMan[][20], char cheatSheat[])
{

    hangMan[cheatSheat[27]][cheatSheat[28]] = cheatSheat[29];

}
int main()
{
    system("cls");
    char letter, arrOfUsedLetters[100], word[100], Replacementword[100], wordHolder[100], bodyElements[30] = { 3, 11, '|', 3, 13,'|',4, 12, '-', 5, 12, '|', 6, 12, '|', 5, 11, '/', 5, 13, '\\',7, 11, '/', 7, 13, '\\', 3, 12, 'X' };
    int wordLength, rightGuesses = 0;
    int cntMistakes = 0, counter = 0;
    int check = 0;
    cout << "Enter word:" << endl;
    cin.getline(word, 100);
    wordLength = strlen(word);
    int j = 0;
    for (int i = 0; i < wordLength; i++)
    {
        Replacementword[i] = '_';
        wordHolder[i] = word[i];
    }
    Replacementword[0] = word[0];
    Replacementword[wordLength - 1] = word[wordLength - 1];
    //3, 11, 3, 13, 4, 12, 5, 12, 6, 12 
    bool running = true;
    char hangMan[10][20]
    {
        {' ','_', '_', '_', '_', '_', '_', '_', '_','_','_', '_', '_', '_', '_', '_', '_', '_'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    while (running)
    {
        printHangMan(hangMan);

        if (checkForCompletion(Replacementword, wordLength) && cntMistakes < 5)
        {
            for (int i = 0; i < wordLength; i++)
            {
                cout << Replacementword[i];
            }
            cout << endl;

            cout << "Congrats, you guessed the word!" << endl;

            cout << "The word was ";
            for (int i = 0; i < wordLength; i++)
            {
                cout << wordHolder[i];
            }
            cout << ".";
            break;
        }
        else if (cntMistakes >= 5)
        {
            for (int i = 0; i < wordLength; i++)
            {
                cout << Replacementword[i];
            }
            cout << endl;

            cout << "You lost!" << endl;

            cout << "The word was ";
            for (int i = 0; i < wordLength; i++)
            {
                cout << wordHolder[i];
            }
            cout << ".";
            break;

        }
        cout << "Time to guess the word!" << endl;

        for (int i = 0; i < wordLength; i++)
        {
            cout << Replacementword[i];
        }
        cin >> letter;
        arrOfUsedLetters[counter] = letter;

        //1
        //2
        //3
        //4
        for (int i = 0; i < strlen(arrOfUsedLetters); i++)
        {

            if (arrOfUsedLetters[i] == letter)
            {
                check++; break;
            }

        }

        //1
        //1
        //2
        //2
        int mistakes = rightGuesses;
        //0
        //1
        for (int j = 0; j < wordLength; j++)
        {

            if (letter == word[j])
            {
                updateHangMan(hangMan, Replacementword, letter, j);
                rightGuesses++;
                word[j] = '*';
            }
        }
        //1
        //2
        //1
        if (rightGuesses == mistakes)
        {
            cntMistakes++;
            switch (cntMistakes)
            {
            case 1: updateHead(hangMan, bodyElements); break;
            case 2: updateBody(hangMan, bodyElements); break;
            case 3: updateArms(hangMan, bodyElements); break;
            case 4: updateLegs(hangMan, bodyElements); break;
            case 5: updateFinalCross(hangMan, bodyElements);
            }
        }


    }
}


