#include <stdio.h>
#include <string.h>
#include "word_checker.h"
#include <ctype.h>

char get_letter(int i, int j, struct rolled_dice **game_board){
    return game_board[i][j].character;
}

int abides_rules(int i, int j, char *word, struct rolled_dice** game_board, int subLen, int **visited){
	int adj_cell;
	char currentLetter = word[subLen];
	int ans = (subLen == (strlen(word)-1));


	if(subLen == (strlen(word)-1)){
		return 1;
	}

	// right, digUpRight, up, digUpLeft, left, digDownLeft, down, digDownRight
	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};

		int newX;
		int newY;
	
		char findLetter;
			  findLetter = word[subLen + 1];
			int result = 0;

			for(adj_cell = 0; adj_cell < 8; adj_cell++){
				int newX = i + allX[adj_cell];
				int newY = j + allY[adj_cell];
				if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == get_letter(newX, newY, game_board) && !visited[newX][newY]){
					visited[newX][newY] = 1;
					++subLen;
					result = abides_rules(newX, newY, word, game_board, subLen, visited);
				if(result){
					return 1;
				}else{
				--subLen;
				}
						
				}
			
		}
	
		return 0;
}


int word_checker(struct rolled_dice **game_board, char *word){
	
	int row, letter, col, m, n;
	int **visited;
	visited = malloc(sizeof(int * ) * 4);

	visited[0] = malloc(sizeof(int) * 4);
	visited[1] = malloc(sizeof(int) * 4);
	visited[2] = malloc(sizeof(int) * 4);
	visited[3] = malloc(sizeof(int) * 4);

	for(m = 0; m < 4; m++){
		for(n = 0; n < 4; n++){
			if(m == 0 && n == 0){
				visited[m][n] = 1;
			}else{
			visited[m][n] = 0;
			}
		}
	}

		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				if(abides_rules(row, col, word, game_board, 0, visited)){
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

char test_get_letter(int i, int j, char **boggle){

	return boggle[i][j];
}



int test_abides_rules(int i, int j, char *word, char **game_board, int subLen, int **visited){
		int adj_cell;
	// use subLen as index to see what letter to find
	char currentLetter = word[subLen];
	int ans = (subLen == (strlen(word)-1));
	if(subLen == (strlen(word)-1)){
		return 1;
	}

	int allX[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int allY[] = {1, 1, 0, -1, -1, -1, 0, 1};

		int newX;
		int newY;
	
		char findLetter;
			if(toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == test_get_letter(i,j,game_board)){
				 findLetter = word[subLen + 3];
				 subLen++;
				 subLen++;
				 currentLetter = word[subLen];
			}else{
				findLetter = word[subLen + 1];
			}
			int result = 0;

			for(adj_cell = 0; adj_cell < 8; adj_cell++){
				int newX = i + allX[adj_cell];
				int newY = j + allY[adj_cell];
				if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) 
					&& toupper(findLetter) == test_get_letter(newX, newY, game_board) 
					&& !visited[newX][newY]){
					visited[newX][newY] = 1;
					++subLen;
					result = test_abides_rules(newX, newY, word, game_board, subLen, visited);
						if(result){
						return 1;
						}else{
						--subLen;
						}
				}
		}
		return 0;
}

// Refactored Code Below - By: Alex Montague
// Remember - Change Function Names
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
