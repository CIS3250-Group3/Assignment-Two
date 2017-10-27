#include <stdio.h>
#include <string.h>
#include "wordChecker.h"
#include <ctype.h>

char getLetter(int i, int j, struct rolledDice **gameBoard) {
	return gameBoard[i][j].character;
}

int abidesRules(int i, int j, char *word, struct rolledDice **gameBoard, int subLen, int **visited) {
	int ans = (subLen == (strlen(word)-1));
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
	int newX = 0;
	int newY = 0;
	int result = 0;
	char currentLetter = word[subLen];
	char findLetter = '';

	if(subLen == (strlen(word)-1)) {
	    return 1;
	}

	// right, digUpRight, up, digUpLeft, left, digDownLeft, down, digDownRight
	findLetter = word[subLen + 1];

	for(int adjCell = 0; adjCell < 8; adjCell++) {
	    int newX = i + allX[adjCell];
	    int newY = j + allY[adjCell];
		if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == get_Letter(newX, newX, gameBoard) && !visited[newX][newY]) {
		    visited[newX][newY] = 1;
			++subLen;
			result = abidesRules(newX, newY, word, gameBoard, subLen, visited);
			if(result) {
				return 1;
			}
			else {
				--subLen;
			}

		}

	}
	return 0;
}

int wordChecker(struct rolledDice **gameBoard, char *word) {

	int **visited = 0;
	visited = malloc(sizeof(int * ) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for(int m = 0; m < 4; m++) {
		for(int n = 0; n < 4; n++) {
		    if(m == 0 && n == 0) {
			    visited[m][n] = 1;
			}
		   	else {
			    visited[m][n] = 0;
			}
		}
	}

	for (int row = 0; row < 4; row++) {
	    for (int col = 0; col < 4; col++) {
		    if(abidesRules(row, col, word, gameBoard, 0, visited)) {
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

char testGetLetter(int i, int j, char **boggle) {
    return boggle[i][j];
}

int testGetLetter(int i, int j, char *word, char **gameBoard, int subLen, int **visited) {
    int all_X[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int all_Y[] = {1, 1, 0, -1, -1, -1, 0, 1};
	int newX = 0;
	int newY = 0;
    int ans = (subLen == (strlen(word)-1));
    int result = 0;
    char currentLetter = word[subLen];
    char findLetter = '';

	// use subLen as index to see what letter to find
  	if(subLen == (strlen(word)-1)) {
	    return 1;
  	}

    if(toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == testGetLetter(i,j,gameBoard)) {
	    findLetter = word[subLen + 3];
		subLen++;
		subLen++;
		currentLetter = word[subLen];
	}
	else {
	    findLetter = word[subLen + 1];
	}

	for(int adjCell = 0; adjCell < 8; adjCell++) {
    	int newX = i + all_X[adjCell];
		int newY = j + all_Y[adjCell];
		if((newX >= 0) && (newX < 4) && (newY >= 0) && (newY < 4) && toupper(findLetter) == testGetLetter(newX, newY, gameBoard) && !visited[newX][newY]) {
			visited[newX][newY] = 1;
			++subLen;
			result = testAbidesRules(newX, newX, word, gameBoard, subLen, visited);
			if(result) {
			    return 1;
		  	}
			else {
				--subLen;
			}
	    }
    }
  	return 0;
}

int testWordChecker(char **boggle, char *word) {
	int **visited = malloc(sizeof(int*) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for(int m = 0; m < 4; m++) {
		for(int n = 0; n < 4; n++) {
			if(m == 0 && n == 0) {
				visited[m][n] = 1;
			}
			else{
				visited[m][n] = 0;
			}
		}
	}

	for(int row = 0; row < 4; row++) {
		for(int col = 0; col < 4; col++) {
			if(test_abides_rules(row, col, word, boggle, 0, visited)) {
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

int hcWordChecker(char boggle[][4], char *word) {
	int **visited = malloc(sizeof(int*) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for(int m = 0; m < 4; m++) {
		for(int n = 0; n < 4; n++) {
			if(m == 0 && n == 0) {
				visited[m][n] = 1;
			}
			else {
				visited[m][n] = 0;
			}
		}
	}

	for(int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if(hcAbidesRules(row, col, word, boggle, 0, visited)) {
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


int hcAbidesRules(int i, int j, char* word, char boggle[][4], int subLen, int** visited) {
	int adjCell;
	int ans = (subLen == (strlen(word) - 1));
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};
	int newX = i + allX[adjCell];
	int newY = j + allY[adjCell];
	int result = 0;
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

	for(adjCell = 0; adjCell < 8; adjCell++) {
		if((newX >= 0) && (newX < 4) && (newY >= 0) && (newY < 4) && toupper(findLetter) == hcGetLetter(newX, newY, boggle) && !visited[newX][newY]) {
			visited[newX][newY] = 1;
			subLen++;
			result = hcAbidesRules(newX, newY, word, boggle, subLen, visited);

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



char hcGetLetter(int i, int j, char boggle[][4]) {
	return boggle[i][j];
}
