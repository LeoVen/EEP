#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // getch

#define WORLD_SIZE 32

int xadd (int i, int a) {
	i += a;
	while (i < 0) i += WORLD_SIZE;
	while (i >= WORLD_SIZE) i -= WORLD_SIZE;
	return i;
}

/* add to a height index, wrapping around */

int yadd (int i, int a) {
	i += a;
	while (i < 0) i += WORLD_SIZE;
	while (i >= WORLD_SIZE) i -= WORLD_SIZE;
	return i;
}

unsigned cn(int **w, unsigned x, unsigned y)
{
	unsigned r = 0, i, j;

	for(i = -1; i < 2; i++)
	{
		for(j = -1; j < 2; j++)
		{
			if (i || j)
				if (w[xadd(x, i)][yadd(y, j)])
					r++;
		}
	}

	return r;
}
/*
// Counts neighbours
// Boundaries are counted as dead cells
unsigned cn(int **w, unsigned x, unsigned y)
{
	unsigned r = 0;

	// Upper cells
	if (x != 0)
	{
		// Check if upper cell is alive
		if (w[x - 1][y] != 0)
			r++;

		if (y != 0)
		{
			// Check if upper left cell is alive
			if (w[x - 1][y - 1] != 0)
				r++;

			// Check if left cell is alive
			if (w[x][y - 1] != 0)
				r++;
		}

		if (y != WORLD_SIZE - 1)
		{
			// Check if upper right cell is alive
			if (w[x - 1][y + 1] != 0)
				r++;

			// Check if right cell is alive
			if (w[x][y + 1] != 0)
				r++;
		}
	}

	// Lower cells
	if (x != WORLD_SIZE - 1)
	{
		// Check if lower cell is alive
		if (w[x + 1][y] != 0)
			r++;

		if (y != 0)
		{
			// Check if lower left cell is alive
			if (w[x + 1][y - 1] != 0)
				r++;
		}

		if (y != WORLD_SIZE - 1)
		{
			// Check if lower right cell is alive
			if (w[x + 1][y + 1] != 0)
				r++;
		}
	}

	return r;
}
*/
int evolve(int **w, int **c, unsigned x, unsigned y)
{
	// Number of neighbours
	unsigned n = cn(w, x, y);

	if (n < 2 || n > 3)
		c[x][y] = 0;
	else if (n == 3)
		c[x][y] = 1;

	return 0;
}

void display(int **w)
{
	unsigned i, j;
	for (i = 0; i < WORLD_SIZE; i++)
	{
		for (j = 0; j < WORLD_SIZE; j++)
			printf("%s", (w[i][j] == 0) ? "   " : " # ");

		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	unsigned i, j, k, x, y;
	int **world = malloc(sizeof(int*) * WORLD_SIZE);
	int **copy = malloc(sizeof(int*) * WORLD_SIZE);

	for (i = 0; i < WORLD_SIZE; i++)
	{
		world[i] = malloc(sizeof(int) * WORLD_SIZE);
		copy[i] = malloc(sizeof(int) * WORLD_SIZE);
	}

	for (i = 0; i < WORLD_SIZE; i++)
	{
		for (j = 0; j < WORLD_SIZE; j++)
		{
			world[i][j] = 0;
			copy[i][j] = 0;
		}

	}

	// Setting initial position
	x = 10, y = 10;
	world[  x  ][y - 1] = 1;
	world[x + 1][  y  ] = 1;
	world[  x  ][y + 1] = 1;
	world[x - 1][y + 1] = 1;
	world[x - 2][y + 1] = 1;

	for (i = 0; i < WORLD_SIZE; i++)
		for (j = 0; j < WORLD_SIZE; j++)
			copy[i][j] = world[i][j];

	// Maximum generations
	unsigned max = 10;

	char c; // getch

	for (k = 0; k < max; k++)
	{
		display(world);

		for (i = 0; i < WORLD_SIZE; i++)
		{
			for (j = 0; j < WORLD_SIZE; j++)
			{
				evolve(world, copy, i, j);
			}
		}

		for (x = 0; x < WORLD_SIZE; x++)
			for (y = 0; y < WORLD_SIZE; y++)
				world[x][y] = copy[x][y];

		c = getch();

		system("cls");
	}

	for (i = 0; i < WORLD_SIZE; i++)
	{
		free(world[i]);
		free(copy[i]);
	}

	free(world);
	free(copy);

	return 0;
}
