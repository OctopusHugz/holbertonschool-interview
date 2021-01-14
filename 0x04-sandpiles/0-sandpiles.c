#include "sandpiles.h"

/**
 * sandpiles_sum - returns the sum of 2 sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: stable sum of the 2 sandpiles
 **/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y, topple_count = 0, grid3_tc = 0, grid3[3][3];

	add_sandpiles(grid1, grid2);
	topple_count = is_stable_sandpile(grid1);
	if (topple_count == 0)
		return;
	printf("=\n");
	print_grid(grid1);
	printf("=\n");
	while (topple_count > 0)
	{
		topple(grid1);
		topple_count = is_stable_sandpile(grid1);
		if (topple_count > 0)
		{
			for (x = 0; x < 3; x++)
			{
				for (y = 0; y < 3; y++)
					grid3[x][y] = 0;
			}
			print_grid(grid1);
			add_sandpiles(grid3, grid1);
			grid3_tc = is_stable_sandpile(grid3);
			if (grid3_tc > 0)
			{
				topple(grid3);
				grid3_tc = is_stable_sandpile(grid3);
				if (grid3_tc > 0)
					printf("=\n");
			}
			/* if (topple_count > 1)
				printf("=\n"); */
		}
	}
}

/**
 * topple - topples a sandpile
 * @grid1: sandpile to topple
 * @topple_count: number of sandpiles to topple
 **/

void topple(int grid1[3][3])
{
	int x, y, toppled[3][3];

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] > 3)
				toppled[x][y] = 1;
			else
				toppled[x][y] = 0;
		}
	}

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (toppled[x][y] == 1)
			{
				{
					grid1[x][y] -= 4;
					if (x > 0)
						grid1[x - 1][y]++;
					if (y > 0)
						grid1[x][y - 1]++;
					if (x < 2)
						grid1[x + 1][y]++;
					if (y < 2)
						grid1[x][y + 1]++;
				}
			}
		}
	}

	/* for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] > 3 &&
				((toppled[x - 1][y] != 1 || toppled[x][y - 1] != 1) ||
				 (toppled[x - 1][y] == 1 || toppled[x][y - 1] == 1)))
			{
				if (((toppled[x - 1][y] == 1 || toppled[x][y - 1] == 1) &&
					 (grid1[x][y] - 1 > 3)) ||
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
				}
			}
		}
	} */
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
