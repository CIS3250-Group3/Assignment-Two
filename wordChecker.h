/*
	file: wordChecker.h
	student email(s): yhovich@uoguelph.ca, isinan@uoguelph.ca, amontagu@uoguelph.ca,
	ssial@uoguelph.ca, ramsayl@uoguelph.ca, mabdulba@uoguelph.ca,
	group #: Group 3 (Section 2)
	date: November 3, 2017
	description: File containing the function definitions accessor functions that verify that the
	rules are abided by for the game.
	Refactored By: Yonatan Hovich
*/

/*Standard Libraries*/
#include <string.h>
#include "boardGenerator.h"
#include <stdlib.h>

/*
 	wordChecker: This function verifies a word is valid on the game board
 	Parameters: RolledDice **gameBoard, char *word
 	Return: int
*/
int wordChecker(RolledDice **gameBoard, char *word);

/*
 	abidesRules: This function verifies that the characters of a word are positioned in a legal way
 	and that the rules of the game are being followed.
 	Parameters: int i, int j, char *word, RolledDice **gameBoard, int subLength, int **visited
 	Return: int
*/
int abidesRules(int i, int j, char *word, RolledDice **gameBoard, int subLen, int **visited);

/*
 	getLetter: This function returns the character specified by indicies (x,y) on the game board
 	Parameters: int i, int j, RolledDice **gameBoard
 	Return: char
*/
char getLetter(int i, int j, RolledDice **game_board);

/*
 	testWordChecker: This function is a test of the computational algorithim (that is the
 	same in the wordChecker function), in that it verfies a word is valid on boggle
 	Parameters: char **boggle, char *word
 	Return: int
*/
int testWordChecker(char **boggle, char *word);

/*
 	testAbidesRules: This function is a test of the computational algorithim (that is the
 	same in the abidesRules function), in that it verifies that the characters of a word are
 	positioned in a legal way
 	Parameters: int i, int j, char *word, char **gameBoard, int subLength, int **visited
 	Return: int
*/
int testAbidesRules(int i, int j, char *word, char **gameBoard, int subLen, int **visited);

/*
 	testGetLetter: This function is a test of the computational algorithim (that is the
 	same in the getLetter function), in that it returns the character specified by indicies
 	(x,y) on boggle.
 	Parameters: int i, int j, char **boggle
 	Return: char
*/
char testGetLetter(int i, int j, char **boggle);

/*
 	hcWordChecker: This function verifies a word is valid on boggle
 	Parameters: char boggle[][4], char *word
 	Return: int
*/
int hcWordChecker(char boggle[][4], char *word);

/*
 	hcGetLetter: This function returns the character specified by indicies (x,y) on boggle
 	Parameters: int i, int j, char boggle[][4]
 	Return: char
*/
char hcGetLetter(int i, int j, char boggle[][4]);

/*
 	hcAbidesRules: This function verifies that the characters of a word are positioned in a legal way
 	and that the rules of the game are being followed.
 	Parameters: int i, int j, char *word, char boggle[][4], int subLength, int **visited
 	Return: int
*/
int hcAbidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited);
