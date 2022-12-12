#pragma once
#include <cstring>
#include "Body.h"
#include "Text.h"
#include "Menu.h"

using namespace std;

int points = 0; 
void runGame()
{

    char letter, FillingWord[10], wordHolder[10], bodyElements[30] = { 3, 11, '|', 3, 13,'|',4, 12, '-', 5, 12, '|', 6, 12, '|', 5, 11, '/', 5, 13, '\\',7, 11, '/', 7, 13, '\\', 3, 12, 'X' };
    int wordLength, rightGuesses = 0, MistakesCounter = 0, counter = 0, mistakes;
    char randomWords[20][10]
    {
        "bottle", "water", "winter", "snow", "giraffe", "elephant", "element", "cockroach", "safety", "burger", "shinning", "beautiful"
    }, word[10];
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
    bool running = true;
        for (int j = 0; j < 10; j++)
        {
            word[j] = randomWords[randomNumber()][j];
        }
        
    wordLength = strlen(word);
    int lastLetter = wordLength - 1;
    for (int i = 0; i < wordLength; i++)
    {
        FillingWord[i] = '_';
        wordHolder[i] = word[i];
    }
    FillingWord[0] = word[0];
    FillingWord[lastLetter] = word[lastLetter];
    if (wordLength > 4)
        FillingWord[wordLength / 2] = word[wordLength / 2];
    
    while (running)
    {
        printHangMan(hangMan);

        if (checkForCompletion(FillingWord, wordLength) && MistakesCounter < 5)
        {
          points += 10;
            for (int i = 0; i < wordLength; i++)
            {
                cout << FillingWord[i];
            }
            cout << endl;

            cout << "Congrats, you guessed the word!" << endl;

            cout << "The word was ";
            for (int i = 0; i < wordLength; i++)
            {
                cout << wordHolder[i];
            }
            break;
        }
        else if (MistakesCounter >= 5)
        {
           points -= 10;
            for (int i = 0; i < wordLength; i++)
            {
                cout << FillingWord[i];
            }
            cout << endl;
            cout << "You lost!" << endl;
            cout << "The word was ";
            for (int i = 0; i < wordLength; i++)
            {
                cout << wordHolder[i];
            }
            break;
        }
        cout << "Time to guess the word!" << endl;

        for (int i = 0; i < wordLength; i++)
        {
            cout << FillingWord[i];
        }
        cin >> letter;
       
        mistakes = rightGuesses;
        for (int j = 0; j < wordLength; j++)
        {

            if (letter == word[j])
            {
                updateText(hangMan, FillingWord, letter, j);
                rightGuesses++;
                word[j] = '*';
            }
        }
        if (rightGuesses == mistakes)
        {
            MistakesCounter++;
            switch (MistakesCounter)
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
    cout << "   Your score is: " << points << endl;
    cout << "   Play Again? [Y/N]";


}