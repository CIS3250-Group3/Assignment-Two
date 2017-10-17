#ifndef CAR
#define CAR
#include <stdio.h>
#include <stdlib.h>

typedef struct car{
	char direction;
	int arival;
	char move;

}car;

car * createCar(char d, char m, int a);
void printCar(void * c);
char getD(car  * c);
char getM(car  * c);
int  getA(car  * c);

#endif 
