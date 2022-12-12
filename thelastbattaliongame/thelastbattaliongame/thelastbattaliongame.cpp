#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void printMenu()
{
    char hangManWord[5][60]
    {
        {' ',' ',' ','[',']',' ',' ','[',']',' ',' ',' ','[',']',' ',' ',' ','[',']',' ',' ',' ',' ','[',']',' ',' ','[',']','[',']',' ',' ',' ','[',']',' ',' ',' ',' ',' ',' ','[',']',' ',' ',' ','[',']',' ',' ',' ','[',']',' ',' ',' ',' ','[',']'},
        {' ',' ',' ','[',']',' ',' ','[',']',' ',' ','[',']','[',']',' ',' ','[',']','\\','\\',' ',' ','[',']',' ','[',']',' ',' ',' ',' ',' ',' ','[',']','\\','\\',' ',' ','/','/','[',']',' ',' ','[',']','[',']',' ',' ','[',']','\\','\\',' ',' ','[',']'},
        {' ',' ',' ','[',']','[',']','[',']',' ','[',']',' ',' ','[',']',' ','[',']',' ','\\','\\',' ','[',']',' ','[',']',' ','[',']',' ',' ',' ','[',']',' ','\\','\\','/','/',' ','[',']',' ','[',']',' ',' ','[',']',' ','[',']',' ','\\','\\',' ','[',']'},
        {' ',' ',' ','[',']',' ',' ','[',']',' ','[',']','[',']','[',']',' ','[',']',' ',' ','\\','\\','[',']',' ','[',']',' ',' ','[',']',' ',' ','[',']',' ',' ',' ',' ',' ',' ','[',']',' ','[',']','[',']','[',']',' ','[',']',' ',' ','\\','\\','[',']'},
        {' ',' ',' ','[',']',' ',' ','[',']',' ','[',']',' ',' ','[',']',' ','[',']',' ',' ',' ',' ','[',']',' ',' ','[',']','[',']',' ',' ',' ','[',']',' ',' ',' ',' ',' ',' ','[',']',' ','[',']',' ',' ','[',']',' ','[',']',' ',' ',' ',' ','[',']'},
    };


    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            cout << hangManWord[i][j];
        }cout << endl;
    }

    cout << endl;

    char hangManMenu[15][22]
    {
        {' ',' ', '_', '_', '_', '_', '_', '_', '_','_','_', '_', '_', '_', '_', '_'},
        { ' ','|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '/'},
        { ' ','|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        { ' ','|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-'},
        { ' ','|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'x', '|'},
        { ' ','|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', ' ',},
        { ' ','|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', '|', '\\'},
        { ' ','|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
        { ' ','|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' ', '\\'},
        { ' ','|'},
        { ' ','|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
        { ' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\'},
        { '/','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\'},
        {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_', '_', '_', '\\'}
    };

    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            cout << hangManMenu[i][j];
        }cout << endl;
    }

    cout << endl;

}

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
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
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
int randomNumber()
{
    srand(time(0));
    //time(0) is the seed, value of the seconds passed since 1970 
    //the seed is the starting value of the random number sequence
    return rand() % 11;
}
void runGame()
{
    char letter, arrOfUsedLetters[100], Replacementword[100], wordHolder[100], bodyElements[30] = { 3, 11, '|', 3, 13,'|',4, 12, '-', 5, 12, '|', 6, 12, '|', 5, 11, '/', 5, 13, '\\',7, 11, '/', 7, 13, '\\', 3, 12, 'X' };
    int wordLength, rightGuesses = 0;
    int cntMistakes = 0, counter = 0;
    int check = 0;


    char randomWords[20][10]
    {
        "bottle", "water", "winter", "snow", "giraffe", "elephant", "element", "cockroach", "safety", "burger", "shinning", "beautiful"
    }, word[10];

    bool flag = true;
    while (flag)
    {
        for (size_t j = 0; j < 10; j++)
        {
            word[j] = randomWords[randomNumber()][j];
        }
        flag = false;
    }
    wordLength = strlen(word);
    int lastLetter = wordLength - 1;
    for (int i = 0; i < wordLength; i++)
    {
        Replacementword[i] = '_';
        wordHolder[i] = word[i];
    }
    Replacementword[0] = word[0];
    Replacementword[lastLetter] = word[lastLetter];
    if (wordLength > 4)
        Replacementword[wordLength / 2] = word[wordLength / 2];
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
    cout << endl;
    cout << "Play Again [Y/N]";
}
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
            break;
        }
    }
}
