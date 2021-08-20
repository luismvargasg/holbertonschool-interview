#include "sandpiles.h"

/**
 * sandpiles_sum - function that computes the sum of two sandpiles.
 * @grid1: Given grid #1.
 * @grid2: Given grid #2.
 *
 * Return: nothing.
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, count = 0;
	int grid3[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int grid4[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] < 4)
				count++;
		}
	if (count < 9)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid1[i][j] >= 4)
				{
					sandpiles(grid3, grid1, i, j);
				}
				else
					grid3[i][j] += grid1[i][j];
		sandpiles_sum(grid3, grid4);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid1[i][j] = grid3[i][j];

	}
}

/**
 * sandpiles - sandpiles calculations
 * @grid3: grid1.
 * @grid1: grid2.
 * @i: interaction number
 * @j: interaction number
 *
 * Return: Nothing.
 */

void sandpiles(int grid3[3][3], int grid1[3][3], int i, int j)
{
	grid3[i][j] += grid1[i][j] - 4;
	if ((i - 1) >= 0 && (i - 1) < 3)
		grid3[i - 1][j] += 1;
	if ((i + 1) >= 0 && (i + 1) < 3)
		grid3[i + 1][j] += 1;
	if ((j - 1) >= 0 && (j - 1) < 3)
		grid3[i][j - 1] += 1;
	if ((j + 1) >= 0 && (j + 1) < 3)
		grid3[i][j + 1] += 1;
}
