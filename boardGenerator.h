/*
	file: boardGenerator.h
	student email(s): yhovich@uoguelph.ca, isinan@uoguelph.ca, amontagu@uoguelph.ca,
	ssial@uoguelph.ca, ramsayl@uoguelph.ca, mabdulba@uoguelph.ca,
	group #: Group 3 (Section 2)
	date: November 3, 2017
	description: File containing the function definitions for PresetDice & RolledDice ADTs
	accessor and mutator functions.
	Refactored By: Yonatan Hovich
*/

/*Checks to see if BOARD_GEN is defined, defines BOARD_GEN if not*/
#ifndef BOARD_GEN
#define BOARD_GEN

/*Standard Libraries*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*ADT of pre-set dice (which keep their values between games).*/
typedef struct presetDice {
	char *configurations;
	int position;
} PresetDice;

/*ADT of rolled dice (which do not keep their values between games).*/
typedef struct rolledDice {
	char character;
	int position;
} RolledDice;

/*
 	initializePresetDice: Initializes the dice in the list of pre-set dice. Call once at program start.
 	Parameters: PresetDice *inputArrayOfDice
 	Return: N/A
*/
void initializePresetDice(PresetDice *inputArrayOfDice);

/*
 	rollButNotShuffleDice: Rolls the dice to be used at the start of each game. Puts the rolled dice in
	gameDice. Does not shuffle the dice. Helper function.
 	Parameters: RolledDice *gameDice, PresetDice *inputArrayOfDice
 	Return: N/A
*/
void rollButNotShuffleDice(RolledDice *gameDice, PresetDice *inputArrayOfDice);

/*
 	shuffleRolledDicePositions: Shuffles an array of rolled dice. Helper function.
 	Parameters: RolledDice *gameDice
 	Return: N/A
*/
void shuffleRolledDicePositions(RolledDice *gameDice);

/*
 	printGameBoard: Prints a visualization of the input array of rolled_dice.
 	Parameters: RolledDice **gameBoard
 	Return: N/A
*/
void printGameBoard(RolledDice **gameBoard);

/*
 	rollDice: Rolls the dice to be used at the start of the game and shuffles them, putting
	the dice into the 2D array gameDice. Call once at the start of every game.
 	Parameters: RolledDice **gameBoard, PresetDice *inputArrayOfDice
 	Return: N/A
*/
void rollDice(RolledDice **gameBoard, PresetDice *inputArrayOfDice);

/*
 	convertToBoard: Rolls the dice to be used at the start of the game and shuffles them, putting
	the dice into the 2D array gameDice. Call once at the start of every game.
 	Parameters: RolledDice **gameBoard, PresetDice *inputArrayOfDice
 	Return: N/A
*/
void convertToBoard(char *letters, char ***board);

/*
 	printHcBoard: Prints a visualization of the input 2D array boggle.
 	Parameters: char boggle[][4]
 	Return: N/A
*/
void printHcBoard(char boggle[][4]);

#endif
