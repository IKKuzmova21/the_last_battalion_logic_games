#pragma once
#include <iostream>
using namespace std;
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