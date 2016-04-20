#include"io.h"

void playGame (array* a, array* b)
{
	int select = 0;	//input
	int x = a->width - 1;
	int y = a->height - 1;
	char turn = 'x';//who plays
	while (select != 'q')
	{
		printArray(a, x, y);
		select = getch();
		switch (select)
		{
			case KEYDOWN:
				if (y > 0)
					y--;
				break;
			case KEYUP:
				if (y < a->height - 1)
					y++;
				break;
			case KEYRIGHT:
				if (x > 0)
					x--;
				break;
			case KEYLEFT:
				if (x < a->width - 1)
					x++;
				break;
			case RETURN:
				if (canPlay (a, y, x))
				{
					a->cell[y][x] = turn;
					if (turn == 'x')
						turn = 'o';
					else
						turn = 'x';
				}
		}
		if (whoWins (a) == 1)
		{
			printf("x won\n");
			return;
		}
		else if (whoWins (a) == -1)
		{
			printf("o won\n");
			return;
		}
	}
}

int getch()
{
        int c;

        system("stty raw -echo");

        c = getchar();

        /* Here comez the hackz */
        if (c == 27)
        {
                int c2 = getchar();

                if (c2 == 91)
                        c = - getchar();
                else
                        /* Pretty sure this is wrong. */
                        c = c2;
        }
        else if (c == 12) /* ^L */
                system("clear");

        system("stty sane");

        return c;
}

/*void AI (array* a, array* b, char turn)
{
	int i, j;

	for (j = 0; j < a->height; j++)
	{
		for (i = 0; i < a->width; i++)
		{
			if (whoWins(add(b, turn, i, j)) == 1 && turn == 'x' || whoWins(add(b, turn, i, j)) == -1 && turn == 'o')
			{
				add(a, turn, i, j);
				return;
			}
			pasteArray(a, b);
		}
	}

	for (j = 0; j < a->height; j++)
	{
		for (i = 0; i < a->width; i++)
		{
			array* c = initArray (a->width, a->height);
			pasteArray(a, c);
			AI (array* a, array* c, char turn);
		}
	}
}TODO*/ 
