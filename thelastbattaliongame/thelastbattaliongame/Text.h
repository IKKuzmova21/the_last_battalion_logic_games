#pragma once
int randomNumber()
{
    srand(time(0));
    //time(0) is the seed, value of the seconds passed since 1970 
    //the seed is the starting value of the random number sequence
    return rand() % 11;
}
void updateText(char hangMan[][20], char word[], char letter, int i)
{
    word[i] = letter;
}

bool checkForCompletion(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '_')
            return false;
    }
    return true;
}