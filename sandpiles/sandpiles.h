#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/* Function Prototypes */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
static void print_grid_sum(int grid1[3][3], int grid2[3][3]);
static bool is_stable(int grid[3][3]);
static void topple(int grid[3][3], int row, int col);

#endif /* SANDPILES_H */
