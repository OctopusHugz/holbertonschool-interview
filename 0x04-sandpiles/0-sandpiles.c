#include "sandpiles.h"

/**
 * sandpiles_sum - returns the sum of 2 sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: stable sum of the 2 sandpiles
 **/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int topple_count = 0;

	add_sandpiles(grid1, grid2);
	/* printf("=\n");
	print_grid(grid1);
	printf("=\n"); */
	topple_count = is_stable_sandpile(grid1);
	if (topple_count == 0)
		return;

	while (topple_count > 0)
	{
		topple(grid1, topple_count);
		topple_count = is_stable_sandpile(grid1);
		if (topple_count > 0)
		{
			print_grid(grid1);
			printf("=\n");
		}
	}
}

/**
 * add_sandpiles - adds together 2 sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 **/

void add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];
	}
}

/**
 * is_stable_sandpile - checks if a sandpile is stable
 * @grid1: sandpile to check for stability
 * Return: number of sandpiles to topple
 **/

int is_stable_sandpile(int grid1[3][3])
{
	int x, y, topple_count = 0;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			if (grid1[x][y] > 3)
				topple_count++;
	}
	return (topple_count);
}

/**
 * topple - topples a sandpile
 * @grid1: sandpile to topple
 * @topple_count: number of sandpiles to topple
 **/

void topple(int grid1[3][3], int topple_count)
{
	int x, y, toppled[3][3];

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			toppled[x][y] = 0;
	}

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] > 3 && topple_count > 0 &&
				(toppled[x - 1][y] != 1 || toppled[x][y - 1] != 1))
			{
				toppled[x][y] = 1;
				grid1[x][y] -= 4;
				if (x > 0)
					grid1[x - 1][y]++;
				if (y > 0)
					grid1[x][y - 1]++;
				if (x < 2)
					grid1[x + 1][y]++;
				if (y < 2)
					grid1[x][y + 1]++;
				topple_count--;
			}
		}
	}
}

/**
 * print_grid - prints a grid
 * @grid: sandpile to print
 **/

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
