#include <string.h>
#include <stdio.h>
#include "dictionary.h"

//form hash value for string s
//this produces a starting value in the dictionary array
unsigned hash(const char *s) {
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval;
}

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

/* make a duplicate of s */
char *copystr(const char *s) { 
	int len = strlen(s);
	char *p = (char *)malloc(len + 1);
	
	if (p != NULL) {
		strncpy(p, s, len);
	}
	p[len] = '\0';

	return p;
}
