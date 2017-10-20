/*
	file: dictionary.h
	student email(s): yhovich@uoguelph.ca, isinan@uoguelph.ca, amontagu@uoguelph.ca,
	ssial@uoguelph.ca, ramsayl@uoguelph.ca, mabdulba@uoguelph.ca,
	group #: Group 3 (Section 2)
	date: October 20, 2017
	description: File containing the function definitions for DictionaryNode ADT accessor
	and mutator functions.
*/

/*Checks to see if DICTIONARY_H is defined, defines DICTIONARY_H if not*/
#ifndef DICTIONARY_H
#define DICTIONARY_H

/*Standard Libraries*/
#include <stdlib.h>

/*Defines constants*/
#define BIG_HASH_SIZE 20000
#define SMALL_HASH_SIZE 100

/*Node of a dictionary*/
typedef struct dictionaryNode {
	char *key;
    struct dictionaryNode *next;
} DictionaryNode;

/*
 	hash: This function forms a hash value for string s. This produces a starting
 	value in the dictionary array.
 	Parameters: const char *s
 	Return: unsigned int
*/
unsigned hash (const char *s);

/*
 	lookup: This function begins searching at an appropriate location (which is 
 	determined based on the remainder of dividing hash value and hash size 
 	values) for the key (in the dictionary) with the same value.
 	Parameters: DictionaryNode **dictionary, int hashSize, const char *key
 	Return: DictionaryNode *
*/
DictionaryNode *lookup (DictionaryNode **dictionary, int hashSize, const char *key);

/*
 	insert: This function inserts a dictionary node at an appropriate location 
 	of the dictionary array.
 	Parameters: DictionaryNode **dictionary, int hashSize, const char *key
 	Return: DictionaryNode *
*/
DictionaryNode *insert (DictionaryNode **dictionary, int hashSize, const char *key);

/*
 	freeDictionary: This function frees the memory that the dictionary array 
 	(and it's nodes) take up.
 	Parameters: DictionaryNode **dictionary, int hashSize
 	Return: N/A
*/
void freeDictionary (DictionaryNode **dictionary, int hashSize);

/*
 	copyString: This function copies the content insides the passed string into 
 	another string, and ensures null termination is present
 	Parameters: const char *s
 	Return: char *
*/
char *copyString (const char *s);

#endif
