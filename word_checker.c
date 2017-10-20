#include <stdio.h>
#include <string.h>
#include "wordChecker.h"
#include <ctype.h>

/*
  Description: This function will get the letter
               stored in a specific place in the
               structure caled rolledDice.
  Parameters: int i, int j, struct rolledDice **gameBoard
  Return: gameBoard[i][i].character
*/
char getLetter(int i, int j, struct rolledDice **gameBoard) {
  return gameBoard[i][j].character;
}

/*
  Description: overall this function is making sure that
               the word inputted by the user during the game
               will meet all of the requirements in order
               for them to achieve a point
  Parameters: int i, int j, char *word, struct rolledDice **gameBoard, int subLen, int **visited
  Return: 0 or 1
*/
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
			}else {
			    --subLen;
			}

				}

		}

		return 0;
}

/*
  Description: This function will check to see
               if the word entered by the user
               actually exists in the game
  Parameters: struct rolledDice **gameBoard, char *word
  Return: 0 or 1
*/
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
			   }else {
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

/*
  Description: This function will show the
               return the letter at its location
               corresponding to a letter in a
               word that the user entered
  Parameters: int i, int j, char **boggle
  Return: boggle[i][j]
*/
char testGetLetter(int i, int j, char **boggle) {

    return boggle[i][j];
}

/*
  Description: This function will
  Parameters: int i, int j, char *word, char **gameBoard, int subLen, int **visited
  Return: 0 or 1
*/
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
		}else {
			  findLetter = word[subLen + 1];
		}

	  for(int adjCell = 0; adjCell < 8; adjCell++) {
        int newX = i + all_X[adjCell];
    		int newY = j + all_Y[adjCell];
    		if((newX >= 0) && (newX < 4) && (newY >= 0) && (newY < 4) &&
        toupper(findLetter) == testGetLetter(newX, newY, gameBoard) &&
        !visited[newX][newY]) {
    			    visited[newX][newY] = 1;
    			    ++subLen;
    			    result = testAbidesRules(newX, newX, word, gameBoard, subLen, visited);
    				  if(result) {
    				      return 1;
    				  }else {
    				      --subLen;
    				  }
    		   }
        }
  	return 0;
}


int test_wordChecker(char **boggle, char *word){
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
				if(testAbidesRules(row, col, word, boggle, 0, visited)){
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

int hc_wordChecker(char boggle[][4], char *word){

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
				if(hc_abidesRules(row, col, word, boggle, 0, visited)){
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


int hc_abidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited){
	int adjCell;
	char currentLetter = word[subLen];
	int ans = (subLen == (strlen(word)-1));
	if(subLen == (strlen(word)-1)){
		return 1;
	}

	int all_x[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int all_y[] = {1, 1, 0, -1, -1, -1, 0, 1};
		int newX;
		int newY;

		char findLetter;
			if(toupper(currentLetter) == 'Q' && toupper(word[subLen + 2]) == hc_get_letter(i,j,boggle)){
				 findLetter = word[subLen + 3];
				 subLen++;
				 subLen++;
				 currentLetter = word[subLen];

			}else{
				findLetter = word[subLen + 1];
			}
			int result = 0;

			for(adjCell = 0; adjCell < 8; adjCell++){
				int newX = i + all_x[adjCell];
				int newY = j + all_y[adjCell];
				if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4)
					&& toupper(findLetter) == hc_get_letter(newX, newY, boggle)
					&& !visited[newX][newY]){
						visited[newX][newY] = 1;
						++subLen;
						result = hc_abidesRules(newX, newY, word, boggle, subLen, visited);

						if(result){
							return 1;
						}else{
							--subLen;
						}

				}

		}

		return 0;
	}



char hc_get_letter(int i, int j, char boggle[][4]){

	return boggle[i][j];
}
