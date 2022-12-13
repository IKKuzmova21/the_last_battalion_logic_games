#include <iostream>
#include <cstring>
#include "RunGame.h"
#include "Body.h"
#include "Text.h"
using namespace std;
int points = 0;
void runGame()
{
    bool running = true;
    char letter, FillingWord[10], wordHolder[10], bodyElements[30] = { 3, 11, '|', 3, 13,'|',4, 12, '-', 5, 12, '|', 6, 12, '|', 5, 11, '/', 5, 13, '\\',7, 11, '/', 7, 13, '\\', 3, 12, 'X' };
    //FillingWord is used to store the empty spaces that have to be filled by the player
    // wordHolder is used so we can print the word afterwards
    // bodyElements includes the row position of the element, the column position and the element itself

    int wordLength, rightGuesses = 0, MistakesCounter = 0, counter = 0, mistakes;
    char randomWords[20][10]
    {
        "bottle", "water", "winter", "snow", "giraffe", "elephant", "element", "cockroach", "safety", "burger", "stream", "beautiful", "shine", "break", "watch", "call","telephone", "line", "leopard","mouse"
    }, word[10];
    //array of random words
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
    }; // base of the hangman
    
    for (int j = 0; j < 10; j++)
    {
        word[j] = randomWords[randomNumber()][j];
    }
    //RandomNumber function chooses a random word
    wordLength = strlen(word);
    int lastLetter = wordLength - 1;
    for (int i = 0; i < wordLength; i++)
    {
        FillingWord[i] = '-'; //fills the word with plank spaces
        wordHolder[i] = word[i];
    }
   
    FillingWord[0] = word[0];
    FillingWord[lastLetter] = word[lastLetter];
    if (wordLength > 4)
        FillingWord[wordLength / 2] = word[wordLength / 2];
    //checks if the word is long enough so we can print the middle letter too
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

            cout << "You didn't guess the word!" << endl;
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
                updateWord(hangMan, FillingWord, letter, j);
                rightGuesses++;
                word[j] = '*';
            }
           
        }
        
        if (rightGuesses == mistakes)  // this checks if there is any difference after entering the next letter
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

    //prints the score and asks if the player wants to play again

}