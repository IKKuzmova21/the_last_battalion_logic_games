#pragma once
int randomNumber();//returns rng

void updateWord(char hangMan[][20], char word[], char letter, int i);//updates the blank spaces

bool checkForCompletion(char arr[], int n); //checks if the planks are filled
