#ifndef BOARD_GEN
#define BOARD_GEN

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


// The pre-set dice which keep their values between games.
typedef struct presetDice {
	char *configurations;
	int position;
} PresetDice;

// The rolled dice which do not keep their values between games.
typedef struct rolledDice {
	char character;
	int position;
} RolledDice;


void initializePresetDice(PresetDice *inputArrayOfDice);
void rollButNotShuffleDice(RolledDice *gameDice, PresetDice *inputArrayOfDice);

void shuffleRolledDicePositions(RolledDice *gameDice);
void printGameBoard(RolledDice **gameBoard);
void rollDice(RolledDice **gameBoard, PresetDice *inputArrayOfDice);

void convertToBoard(char *letters, char ***board);
void printHcBoard(char boggle[][4]);

#endif
