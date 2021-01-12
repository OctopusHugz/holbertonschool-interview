#include "sandpiles.h"

/**
 * sandpiles_sum - returns the sum of 2 sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: stable sum of the 2 sandpiles
 **/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int topple_count = 0, newpiles[3][3], x, y;

	add_sandpiles(grid1, grid2);
	printf("=\n");
	print_grid(grid1);
	printf("=\n");
	topple_count = is_stable_sandpile(grid1);
	if (topple_count == 0)
		return;
	else
	{
		printf("topple_count is: %d\n", topple_count);
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				if (grid1[x][y] < 4)
					newpiles[x][y] = grid1[x][y];
				else
					newpiles[x][y] = 0;
			}
		}
		while (topple_count > 0)
		{
			topple(grid1, newpiles);
			topple_count--;
			/* print_grid(grid1);
			printf("=\n"); */
			/* break; */
		}
	}
	grid1 = newpiles;
}

void add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];
	}
}

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

void topple(int grid1[3][3], int newpiles[3][3])
{
	int x, y;

	/* printf("=\n");
	print_grid(grid1);
	printf("=\n"); */
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] > 3)
			{
				newpiles[x][y] = grid1[x][y] - 4;
				/* print_grid(newpiles);
				printf("=\n"); */
				if (x > 0)
					newpiles[x - 1][y]++;
				if (y > 0)
					newpiles[x][y - 1]++;
				if (x < 2)
					newpiles[x + 1][y]++;
				if (y < 2)
					newpiles[x][y + 1]++;
			}
		}
	}
	grid1 = newpiles;
	print_grid(grid1);
	printf("=\n");
}
