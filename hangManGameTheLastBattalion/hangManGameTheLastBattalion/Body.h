#pragma once
void printHangMan(char hangMan[][20]); // prints hangMan base

void updateHead(char hangMan[][20], char bodyElements[]); // updates the hangMan by adding the head

void updateBody(char hangMan[][20], char bodyElements[]); // updates the hangMan by adding the body

void updateArms(char hangMan[][20], char bodyElements[]); // updates the hangMan by adding the arms

void updateLegs(char hangMan[][20], char bodyElements[]); // updates the hangMan by adding the Legs

void updateFinalCross(char hangMan[][20], char bodyElements[]); // updates the hangMan by adding the final cross on the head