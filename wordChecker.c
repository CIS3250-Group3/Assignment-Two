/*
	file: wordChecker.c
	student email(s): yhovich@uoguelph.ca, isinan@uoguelph.ca, amontagu@uoguelph.ca,
	ssial@uoguelph.ca, ramsayl@uoguelph.ca, mabdulba@uoguelph.ca,
	group #: Group 3 (Section 2)
	date: November 3, 2017
	description: File containing the source code for functions to check validity of
	inputted words from the user based on game rules
*/

/*Standard/User Defined Libraries*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "wordChecker.h"

// getLetter: This function returns the character specified by indicies (x,y) on the game board
char getLetter(int i, int j, RolledDice **gameBoard) {
    return gameBoard[i][j].character;
}

/*
 	abidesRules: This function verifies that the characters of a word are positioned in a legal way
 	and that the rules of the game are being followed.
*/
int abidesRules(int i, int j, char *word, RolledDice **gameBoard, int subLen, int **visited) {
	int adjCell;
	int newX;
	int newY;
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
	int result = 0;
	char findLetter = word[subLen + 1];

	if(subLen == (strlen(word) - 1)) {
		return 1;
	}

	for (adjCell = 0; adjCell < 8; adjCell++) {
		newX = i + allX[adjCell];
		newY = j + allY[adjCell];
		if ((newX >= 0) && (newX < 4) && (newY >= 0) && (newY < 4) && toupper(findLetter) == getLetter(newX, newY, gameBoard) && !visited[newX][newY]) {
			visited[newX][newY] = 1;
			subLen++;
			result = abidesRules(newX, newY, word, gameBoard, subLen, visited);
			
			if(result) {
				return 1;
			}
			else {
				subLen--;
			}	
		}
	
	}
	return 0;
}

//wordChecker: This function verifies a word is valid on the game board
int wordChecker(RolledDice **gameBoard, char *word) {
	int m;
	int n;
	int **visited = malloc(sizeof(int *) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for (m = 0; m < 4; m++) {
		for (n = 0; n < 4; n++) {
			if (m == 0 && n == 0) {
				visited[m][n] = 1;
			}
			else {
				visited[m][n] = 0;
			}
		}
	}

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (abidesRules(row, col, word, gameBoard, 0, visited)) {
				free(visited[0]);
				free(visited[1]);
				free(visited[2]);
				free(visited[3]);
				return 1;
			}
		}
	}
	
	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;
}

/*
 	testGetLetter: This function is a test of the computational algorithim (that is the
 	same in the getLetter function), in that it returns the character specified by indicies
 	(x,y) on boggle.
*/
char testGetLetter(int i, int j, char **boggle) {
	return boggle[i][j];
}

/*
 	testAbidesRules: This function is a test of the computational algorithim (that is the
 	same in the abidesRules function), in that it verifies that the characters of a word are
 	positioned in a legal way
*/
int testAbidesRules(int i, int j, char *word, char **gameBoard, int subLen, int **visited) {
	int adjCell;
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
	int result = 0;
	int newX;
	int newY;
	char findLetter;
	char currentLetter = word[subLen];

	if (subLen == (strlen(word) - 1)) {
		return 1;
	}
	
	if (toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == testGetLetter(i, j, gameBoard)) {
		findLetter = word[subLen + 3];
		subLen++;
		subLen++;
		currentLetter = word[subLen];
	}
	else {
		findLetter = word[subLen + 1];
	}

	for (adjCell = 0; adjCell < 8; adjCell++) {
		newX = i + allX[adjCell];
		newY = j + allY[adjCell];
		if ((newX >= 0) && (newX < 4) && (newY >= 0) && (newY < 4) && toupper(findLetter) == testGetLetter(newX, newY, gameBoard) && !visited[newX][newY]) {
			visited[newX][newY] = 1;
			subLen++;
			result = testAbidesRules(newX, newY, word, gameBoard, subLen, visited);
			
			if (result) {
				return 1;
			}
			else {
				subLen--;
			}
		}
	}
	return 0;
}

/*
 	testWordChecker: This function is a test of the computational algorithim (that is the
 	same in the wordChecker function), in that it verfies a word is valid on boggle
*/
int testWordChecker(char **boggle, char *word) {

	int **visited = malloc(sizeof(int *) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for (int m = 0; m < 4; m++) {
		for (int n = 0; n < 4; n++) {
			if (m == 0 && n == 0) {
				visited[m][n] = 1;
			}
			else {
				visited[m][n] = 0;
			}
		}
	}

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (testAbidesRules(row, col, word, boggle, 0, visited)) {
				free(visited[0]);
				free(visited[1]);
				free(visited[2]);
				free(visited[3]);
				return 1;
			}
		}
	}

	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;
}

// hcWordChecker: This function verifies a word is valid on boggle
int hcWordChecker(char boggle[][4], char *word) {

	int **visited = malloc(sizeof(int *) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for (int m = 0; m < 4; m++) {
		for (int n = 0; n < 4; n++) {
			if (m == 0 && n == 0) {
				visited[m][n] = 1;
			}
			else {
				visited[m][n] = 0;
			}
		}
	}

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (hcAbidesRules(row, col, word, boggle, 0, visited)) {
				free(visited[0]);
				free(visited[1]);
				free(visited[2]);
				free(visited[3]);
				return 1;
			}
		}	
	}

	free(visited[0]);
	free(visited[1]);
	free(visited[2]);
	free(visited[3]);

	return 0;
}

/*
 	hcAbidesRules: This function verifies that the characters of a word are positioned in a legal way
 	and that the rules of the game are being followed.
*/
int hcAbidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited) {
	int adjCell = 0;
	int result = 0;
	int newX = 0;
	int newY = 0;
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
	char currentLetter = word[subLen];
	char findLetter;

	if(subLen == (strlen(word) - 1)) {
		return 1;
	}
	
	if(toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == hcGetLetter(i, j, boggle)) {
		 findLetter = word[subLen + 3];
		 subLen++;
		 subLen++;
		 currentLetter = word[subLen];
	}
	else { 
		findLetter = word[subLen + 1];
	}

	for (adjCell = 0; adjCell < 8; adjCell++) {
		newX = i + allX[adjCell];
		newY = j + allY[adjCell];
		if ((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == hcGetLetter(newX, newY, boggle) && !visited[newX][newY]) {
			visited[newX][newY] = 1;
			subLen++;
			result = hcAbidesRules(newX, newY, word, boggle, subLen, visited);

			if (result) {
				return 1;
			}
			else {
				subLen--;
			}	
		}
	}
	return 0;
}

// hcGetLetter: This function returns the character specified by indicies (x,y) on boggle
char hcGetLetter(int i, int j, char boggle[][4]) {

	return boggle[i][j];
}
