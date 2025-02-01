#include "sandpiles.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++) {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * is_stable - Check if a sandpile is stable
 * @grid: 3x3 grid
 * Return: true if stable, false otherwise
 */
static bool is_stable(int grid[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return false;
            }
        }
    }
    return true;
}

/**
 * topple - Topple a sandpile at a given position
 * @grid: 3x3 grid
 * @row: row index
 * @col: column index
 */
static void topple(int grid[3][3], int row, int col) {
    grid[row][col] -= 4;
    if (row - 1 >= 0) grid[row - 1][col]++;
    if (row + 1 < 3) grid[row + 1][col]++;
    if (col - 1 >= 0) grid[row][col - 1]++;
    if (col + 1 < 3) grid[row][col + 1]++;
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;
    bool unstable = true;

    while (unstable) {
        unstable = false;

        // Add grid2 to grid1
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                grid1[i][j] += grid2[i][j];
            }
        }

        // Check stability and topple if necessary
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (grid1[i][j] > 3) {
                    unstable = true;
                    topple(grid1, i, j);
                }
            }
        }

        // Print grid1 if unstable
        if (unstable) {
            printf("=\n");
            print_grid(grid1);
        }
    }
}
