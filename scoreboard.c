/*
	file: scoreboard.c
	student email(s): yhovich@uoguelph.ca, isinan@uoguelph.ca, amontagu@uoguelph.ca,
	ssial@uoguelph.ca, ramsayl@uoguelph.ca, mabdulba@uoguelph.ca,
	group #: Group 3 (Section 2)
	date: November 3, 2017
	description: File containing the source code for accessor and mutator functions 
	for User ADT
*/

/*Standard/User Defined Libraries*/
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "scoreboard.h"

/*
 * Finds and returns a pointer to the User in the linked list beginning with
 * head which has the name nameToFind. If such a User is not in the Linked
 * List, it will return NULL. Helper function to increment_score.
 */
User *findUserWithName(User *head, char *nameToFind) {
	if (head == NULL) {
		return head;
	}
	User *current = head;
	while (current != NULL) {
		if (strcmp(current->name, nameToFind) == 0) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

// freeAll: This function frees the memory of all elements of the linked list.
void freeAll(User *head) {
	if (head->next == NULL) {
		free(head);
	}
	else {
		User *current = head->next;
		User *previous = head;
		while (current != NULL) {
			free(previous);
			previous = current;
			current = current->next;
		}
	}
}

// getUserAtIndex: Finds and returns a the User in the linked list at a specified index
User *getUserAtIndex(User *head, int index) {
	if (head == NULL) {
		return NULL;
	}
	User *current = head;
	int count = 0;
	while (current != NULL) {
		if (count == index + 1) {
			return current;
		}
		current = current->next;
		count++;
	}
	return NULL;
}

/*
 	getIndexOfUserWithName: Finds and returns a the index in the linked list based on the specified 
 	name of user
*/
int getIndexOfUserWithName(User *head, char *nameToFind) {
	if (head == NULL && head->name != nameToFind) {
		return -1;
	}
	User *current = head;
	int count = 0;
	while (current != NULL) {
		if (strcmp(current->name, nameToFind)) {
			return count;
		}
		current = current->next;
		count++;
	}
	return -1;
}

/*
 	userIsInList: Finds whether or not a an existing user is already in the list. If they are,
 	returns 1. If not, returns 0.
*/
int userIsInList(User *head, char *nameToFind) {
	User *current = head;
	while (current != NULL) {
		if (strcmp(current->name, nameToFind) == 0) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}

// getLength: Finds and returns the amount of User nodes in the linked list
int getLength(User *head) {
	if (head == NULL) {
		return 0;
	}
	User *current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		if (current->next == NULL) {
			return count;
		}
		current = current->next;
	}
	return 0;
}

/*
 	getLastNode: Finds the last node in the linked list and returns it. Returns NULL if called
 	with an empty head, although such a case is not used in the main function addNode. Helper function.
*/
User *getLastNode(User *head) {
	if (head == NULL) {
		return head;
	}
	User *current = head;
	while (current != NULL) {
		if (current->next == NULL) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

// printScoreboard: Outputs the player name, high score, games played, total score in an organized format
void printScoreboard(User *head) {
        fprintf(stdout, "\n");
        fprintf(stdout, "---- SCORE BOARD ---- \n");
	if (head->next != NULL) {
		User *current = head->next;
		while (current != NULL) {
			printf("\n");
			printf("Player name: %s \n", current->name);
			printf("High score: %d \n", current->maxScore);
			printf("Games played: %d \n", current->totalGames);
			printf("Total score: %d \n", current->totalScore);
			printf("\n");
			printf("--------------------- \n");

			if (current->next == NULL) {
				break;
			}
			current = current->next;
		}
	}
}

// addNode: Initializes a User Node and inserts it at the tail of the linked list
void addNode(User *head, char *name, int maxScore) {
	User *userPtr = NULL;
	if (head != NULL) {
		 userPtr = malloc(sizeof(User));
	}
	strcpy(userPtr->name, name);
	userPtr->maxScore = maxScore;
	userPtr->totalGames = 1;
	userPtr->totalScore = maxScore;
	userPtr->next = NULL;

	if (head == NULL) {
		head = userPtr;
	}
	else {
		getLastNode(head)->next = userPtr;
	}
}

// updateNodeWithName: Updates the User score by finding the user in the linked list by it's name.
void updateNodeWithName(User *head, char *name, int currentScore) {
	if (userIsInList(head, name) == 1) {
		User *userPtr = findUserWithName(head, name);
		if (currentScore > (userPtr->maxScore)) {
			userPtr->maxScore = currentScore;
		}
		userPtr->totalGames += 1;
		userPtr->totalScore += currentScore;
	}
}
