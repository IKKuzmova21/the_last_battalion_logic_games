#include <iostream>
#include "Text.h"
int randomNumber()
{
    srand(time(0));

    //time(0) is the seed, representing the seconds of the system clock
    //the seed is the value of the rand function

    return rand() % 20;
    // % 20 returns a number between 0 and 19
}
void updateWord(char hangMan[][20], char word[], char letter, int i)
{
    word[i] = letter;
}

bool checkForCompletion(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '-')
            return false;
    }
    return true;
}