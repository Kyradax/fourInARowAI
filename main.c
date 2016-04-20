#include"io.h"
#include"array.h"

int main (int argc, char *argv[])
{
	array* a = initArray (7, 5);
	array* b = initArray (7, 5);
	playGame (a, b);
	freeArray (a);
	freeArray (b);

	return 0;
}
