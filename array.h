#ifndef ARRAY_H
#define ARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<limits.h>

typedef struct
{
	int width;
	int height;
	char** cell;
} array;

array* initArray (int width, int height);
void freeArray (array* a);
void printArray (array* a, int x, int y);
int canPlay (array* a, int y, int x);		//Returns 0 if a->cell[x][y] is not playable, 1 instead
int whoWins (array* a);				//Returns 0 if nobody wins, returns 1 if player2 wins, return -1 if player1 wins
void pasteArray (array* a, array* b);
array* add (array* a, char val, int x, int y);

#endif
