#include "sandpiles.h"

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: The sandpile
 * Return: 1 if the sandpile is stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - topples an unstable sandpile
 * @grid: The sandpile
 * Return: Nothing
 */
void topple(int grid[3][3])
{
	int i, j, copy_grid[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			copy_grid[i][j] = grid[i][j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
			{
				copy_grid[i][j] -= 4;
				if (i + 1 < 3)
					copy_grid[i + 1][j] += 1;
				if (i - 1 >= 0)
					copy_grid[i - 1][j] += 1;
				if (j + 1 < 3)
					copy_grid[i][j + 1] += 1;
				if (j - 1 >= 0)
					copy_grid[i][j - 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = copy_grid[i][j];
		}
	}
}

/**
 * sandpiles_sum - sums two stable sandpiles and prints the pile before
 * toppling if the resulting pile is unstable
 * @grid1: the first sandpile
 * @grid2: the second sandpile
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (!is_stable(grid1))
	{
		printf("=\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j)
					printf(" ");
				printf("%d", grid1[i][j]);
			}
			printf("\n");
		}
		topple(grid1);
	}
}
