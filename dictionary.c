/*
	file: dictionary.c
	student email(s): yhovich@uoguelph.ca, isinan@uoguelph.ca, amontagu@uoguelph.ca,
	ssial@uoguelph.ca, ramsayl@uoguelph.ca, mabdulba@uoguelph.ca,
	group #: Group 3 (Section 2)
	date: November 3, 2017
	description: File containing the source code for accessor and mutator functions 
	for DNode ADT
	Refactored By: Yonatan Hovich
*/

/*Standard/User Defined Libraries*/
#include <string.h>
#include <stdio.h>
#include "dictionary.h"

/*
 	hash: This function forms a hash value for string s. This produces a starting
 	value in the dictionary array.
*/
unsigned hash(const char *s) {
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval;
}

/*
 	lookup: This function begins searching at an appropriate location (which is 
 	determined based on the remainder of dividing hash value and hash size 
 	values) for the key (in the dictionary) with the same value.
*/
DNode *lookup(DNode **dictionary, int hashSize, const char *key) {
	DNode *np;
	unsigned int hashval = hash(key);
	for (np = dictionary [hashval % hashSize]; np != NULL; np = np->next) {
		if (strcmp(key, np->key) == 0) {
			return np; 
		}
	}
	return NULL; //not found
}

/*
 	insert: This function inserts a dictionary node at an appropriate location 
 	of the dictionary array.
*/
DNode *insert(DNode **dictionary, int hashSize, const char *key) {
	unsigned int hashval;
	DNode *np;

	if ((np = lookup(dictionary, hashSize, key)) == NULL) {
		np = (DNode *)malloc(sizeof(*np));

		if (np == NULL || (np->key = copystr(key)) == NULL) {
			return NULL;
		}

		hashval = hash(key) % hashSize;

		np->next = dictionary[hashval];
		dictionary[hashval] = np;
	}
	return np;
}

/*
 	freeDictionary: This function frees the memory that the dictionary array 
 	(and it's nodes) take up.
*/
void freeDictionary(DNode **dictionary, int hashSize) {
	for (int i = 0; i < hashSize; i++) { 
		//if there is an entry at position i
		if (dictionary [i] != NULL) { 
			DNode *head = dictionary[i]; 
			DNode *current = head;
			while (current != NULL) {
				DNode * temp = current;
				current = current->next;
				free(temp);
			}
			dictionary[i] = NULL;
		}
	}
}

/*
 	copyString: This function copies the content insides the passed string into 
 	another string, and ensures null termination is present
*/
char *copystr(const char *s) { 
	int len = strlen(s);
	char *p = (char *)malloc(len + 1);
	
	if (p != NULL) {
		strncpy(p, s, len);
	}
	p[len] = '\0';

	return p;
}
