#ifndef IO_H
#define IO_H

#include "array.h"

#define KEYUP -65
#define KEYDOWN -66
#define KEYRIGHT -67
#define KEYLEFT -68
#define RETURN 13

void playGame (array* a, array* b);
int getch();
void AI (array* a, array* b, char turn);

#endif
