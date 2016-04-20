#include"array.h"

array* initArray (int width, int height)
{
	int i, j;

	array* a = malloc(sizeof(array*));
	a->width = width;
	a->height = height;

	a->cell = malloc(height * sizeof(char*));
	for (i = 0; i < height; i++)
	{
		a->cell[i] = malloc(width * sizeof(char));
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			a->cell[i][j] = '-';
		}
	}
	
	return a;
}

void freeArray (array* a)
{
	int i;

	for (i = 0; i < a->height; i++)
	{
		free(a->cell[i]);
	}
	free(a->cell);
	free(a);
}

void printArray (array* a, int x, int y)
{
	int i, j;

	printf("\033[2J\033[0H");
	for (i = a->height - 1; i >= 0; i--)
	{
		for (j = a->width - 1; j >= 0; j--)
		{
			if (x == j && y == i)
				printf("| \033[47m%c\033[00m ", a->cell[i][j]);
			else if (canPlay(a, i, j))
				printf("| \033[32m%c\033[00m ", a->cell[i][j]);
			else
				printf("| %c ", a->cell[i][j]);
		}
		printf("|\n");
		for (j = 0; j < a->width; j++)
		{
			printf(" ___");
		}
		printf("\n");
	}
	printf("%d %d\n", x, y);
}

int canPlay (array* a, int y, int x)
{
	if (a->cell[y][x] == '-')
	{
		if (y == 0)
			return 1;
		else if (a->cell[y-1][x] != '-')
			return 1;
	}
	return 0;
}

int whoWins (array* a)
{
	int i, j;

	for (i = 0; i < a->height; i++)
	{
		for (j = 0; j < a->width; j++)
		{
			if (i < a->height - 3)
			{
				if (a->cell[i][j] == a->cell[i+1][j] && a->cell[i][j] == a->cell[i+2][j] && a->cell[i][j] == a->cell[i+3][j])
				{
					if (a->cell[i][j] == 'x')
						return 1;
					else if (a->cell[i][j] == 'o')
						return -1;
				}
			}
			if (j < a->width - 3)
			{
				if (a->cell[i][j] == a->cell[i][j+1] && a->cell[i][j] == a->cell[i][j+2] && a->cell[i][j] == a->cell[i][j+3])
				{
					if (a->cell[i][j] == 'x')
						return 1;
					else if (a->cell[i][j] == 'o')
						return -1;
				}
			}
			if (j < a->width - 3 && i >= 3)
			{
				if (a->cell[i][j] == a->cell[i-1][j+1] && a->cell[i][j] == a->cell[i-2][j+2] && a->cell[i][j] == a->cell[i-3][j+3])
				{
					if (a->cell[i][j] == 'x')
						return 1;
					else if (a->cell[i][j] == 'o')
						return -1;
				}
			}
			if (j >= 3 && i < a->height - 3)
			{
				if (a->cell[i][j] == a->cell[i+1][j-1] && a->cell[i][j] == a->cell[i+2][j-2] && a->cell[i][j] == a->cell[i+3][j-3])
				{
					if (a->cell[i][j] == 'x')
						return 1;
					else if (a->cell[i][j] == 'o')
						return -1;
				}
			}
		}
	}

	return 0;
}

void pasteArray (array* a, array* b)
{
	int i, j;

	if (a->height != b->height || a->width != b->width)
	{
		printf("Error, both the arrays don't have the same size\n");
		exit(1);
	}

	for (i = 0; i < a->height; i++)
	{
		for (j = 0; j < a->width; j++)
		{
			b->cell[i][j] = a->cell[i][j];
		}
	}
}

array* add (array* a, char val, int x, int y)
{
	if (canPlay(a, y, x))
		a->cell[y][x] = val;
	return a;
}
