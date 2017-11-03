#include <string.h>
#include "boardGenerator.h"
#include <stdlib.h>


int wordChecker(RolledDice **gameBoard, char *word);

int abidesRules(int i, int j, char *word, RolledDice **gameBoard, int subLen, int **visited);
char getLetter(int i, int j, RolledDice **game_board);

int testWordChecker(char **boggle, char *word);

int testAbidesRules(int i, int j, char *word, char **gameBoard, int subLen, int **visited);

char testGetLetter(int i, int j, char **boggle);

int hcWordChecker(char boggle[][4], char *word);

char hcGetLetter(int i, int j, char boggle[][4]);

int hcAbidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited);



