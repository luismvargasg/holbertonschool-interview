#ifndef SANDPILES_H
#define SANDPILES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid_sum(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);
void sandpiles(int grid3[3][3], int grid1[3][3], int i, int j);

#endif /* LISTS_H */