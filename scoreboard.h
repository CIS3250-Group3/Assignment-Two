/*
	file: scoreboard.h
	student email(s): yhovich@uoguelph.ca, isinan@uoguelph.ca, amontagu@uoguelph.ca,
	ssial@uoguelph.ca, ramsayl@uoguelph.ca, mabdulba@uoguelph.ca,
	group #: Group 3 (Section 2)
	date: November 3, 2017
	description: File containing the function definitions for User ADTs	accessor and
	mutator functions.
	Refactored By: Yonatan Hovich
*/

/*Checks to see if SCOREBOARD_H is defined, defines SCOREBOARD_H if not*/
#ifndef SCOREBOARD_H
#define SCOREBOARD_H

/*Standard Libraries*/
#include <stdlib.h>

/*ADT of User*/
typedef struct user {
	char name[100];
	int maxScore;
	int totalGames;
	int totalScore;
	struct user *next;
} User;

/*
 	findUserWithName: Finds and returns a pointer to the User in the linked list beginning with
 	head which has the name nameToFind. If such a User is not in the Linked
 	List, it will return NULL. Helper function to incrementScore.
 	Parameters: User *head, char *nameToFind
 	Return: User *
*/
User *findUserWithName(User *head, char *nameToFind);

/*
 	getUserAtIndex: Finds and returns a the User in the linked list at a specified index
 	Parameters: User *head, int index
 	Return: User *
*/
User *getUserAtIndex(User *head, int index);

/*
 	getIndexOfUserWithName: Finds and returns a the index in the linked list based on the specified 
 	name of user
 	Parameters: User *head, char *nameToFind
 	Return: int
*/
int getIndexOfUserWithName(User *head, char *nameToFind);

/*
 	getLength: Finds and returns the amount of User nodes in the linked list
 	Parameters: User *head
 	Return: int
*/
int getLength(User *head);

/*
 	getLastNode: Finds the last node in the linked list and returns it. Returns NULL if called
 	with an empty head, although such a case is not used in the main function addNode. Helper function.
 	Parameters: User *head
 	Return: User *
*/
User *getLastNode(User *head);

/*
 	printScoreboard: Outputs the player name, high score, games played, total score in an organized format
 	Parameters: User *head
 	Return: N/A
*/
void printScoreboard(User *head);

/*
 	freeAll: This function frees the memory of all elements of the linked list.
 	Parameters: User *head
 	Return: N/A
*/
void freeAll(User* head);

/*
 	addNode: Initializes a User Node and inserts it at the tail of the linked list
 	Parameters: User *head, char *name, int maxScore
 	Return: N/A
*/
void addNode(User *head, char *name, int maxScore);

/*
 	userIsInList: Finds whether or not a an existing user is already in the list. If they are,
 	returns 1. If not, returns 0.
 	Parameters: User *head, char *nameToFind
 	Return: int
*/
int userIsInList(User *head, char* nameToFind);

/*
 	updateNodeWithName: Updates the User score by finding the user in the linked list by it's name.
 	Parameters: User *head, char *nameToFind
 	Return: N/A
*/
void updateNodeWithName(User *head, char *name, int currentScore);

#endif
