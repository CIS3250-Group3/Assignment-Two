/*
	file: dictionary.c
	student email(s): yhovich@uoguelph.ca, isinan@uoguelph.ca, amontagu@uoguelph.ca,
	ssial@uoguelph.ca, ramsayl@uoguelph.ca, mabdulba@uoguelph.ca,
	group #: Group 3 (Section 2)
	date: October 20, 2017
	description: File containing the source code for functions of dictionary ADT.
*/

/*Standard Libraries*/
#include <string.h>
#include "dictionary.h"
#include <stdio.h>

/*hash: This function forms a hash value for string s. This produces a starting*/
unsigned int hash (const char *s) {
	//calculates hash value
	for (unsigned int hashVal = 0; *s != '\0'; s++) {
		hashVal = *s + 31 * hashVal;
	}
	return hashVal ;
}

/*
 	lookup: This function begins searching at an appropriate location (which is 
 	determined based on the remainder of dividing hash value and hash size 
 	values) for the key (in the dictionary) with the same value.
*/
DictionaryNode *lookup (DictionaryNode **dictionary, int hashSize, const char *key) {
	//Variable declations and initializations
	unsigned int hashVal = hash(key);

	//determines next dictionary node
	for (DictionaryNode *nextPtr = dictionary[hashVal % hashSize]; nextPtr != NULL; nextPtr = nextPtr->next) {
		if (strcmp (key, nextPtr->key) == 0) {
			return nextPtr; 
		}
	}
	return NULL; //not found
}

/*
 	insert: This function inserts a dictionary node at an appropriate location 
 	of the dictionary array.
*/
DictionaryNode *insert (DictionaryNode **dictionary, int hashSize, const char *key) {
	//Variable declations
	unsigned int hashVal;
	DictionaryNode *nextPtr;

	//checks if lookup function returns empty
	if ((nextPtr = lookup(dictionary, hashSize, key)) == NULL) {
		nextPtr = (DictionaryNode *) malloc(sizeof(*nextPtr)); //casts nextPtr into type DictionaryNode

		//checks if nextPtr is empty or copyString function returns empty
		if (nextPtr == NULL || (nextPtr->key = copyString(key)) == NULL) {
			return NULL;
		}

		hashVal = hash(key) % hashSize; //calculates hash value (remainder of dividing hash value and hash size)

		//inserts dictionary node into dictionary array
		nextPtr->next = dictionary[hashVal];
		dictionary[hashVal] = nextPtr;
	}
	return nextPtr;
}

/*
 	freeDictionary: This function frees the memory that the dictionary array 
 	(and it's nodes) take up.
*/
void freeDictionary (DictionaryNode **dictionary, int hashSize) {
	//Variable declations
	DictionaryNode *head;
	DictionaryNode *current;
	DictionaryNode *temp;

	//loops hashSize number of times
	for (int i = 0; i < hashSize; i++) { 
		//if there is an entry at position i
		if (dictionary[i] != NULL) { 
			head = dictionary[i]; 
			current = head;
			
			//loops until current dictionary node is empty (NULL)
			while (current != NULL) {
				temp = current;
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
char *copyString (const char *s) { /* make a duplicate of s */
	//Variable declations and initializations
	char *p = (char *) malloc(len+1); //+1 for '\0'
	int len = strlen(s);

	//checks if p (string) is empty, if so copies s (string contents)
	if (p != NULL) {
		strncpy(p, s, len);
	}
	p[len] = '\0'; //adds a null terminator char to end of p (string)

	return p;
}
