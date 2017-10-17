/**
 *@file book.h
 *@author Yonatan Hovich
 *@date September 25, 2017
 *@header file includes book struct and it's accessors & mutator functions
 **/

/**Structure containing double variable (to store price) and a string (to store 
 *name) of a book.
 **/
typedef struct book {
	double price;
    char *name;
} Book;

/**This function takes a string and double and dynamically creates a struct of 
 *a book (allocates the memory) needed to store a price and a name.
 *@param title static string of title
 *@param price double
 *@return a dynamically created Book struct*
 **/
Book* createBook( char * title, double price );

/**Get price of book
 *@param b Book
 *@return Double price
 **/
double getBookPrice( Book * b );

/**Return a books name
 *@param b Book
 *@return string of name
 **/
char* getBookName( Book *b );

/**Display a book's name and price
 *@param b [Book]
 **/
void printBook( void * vPtr );
