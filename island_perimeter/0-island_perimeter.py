#!/usr/bin/python3
"""
0-island_perimeter
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid.

    Args:
        grid (list of list of int): The grid representing the island.

    Returns:
        int: The perimeter of the island.

    Constraints:
        - 0 represents water.
        - 1 represents land.
        - Cells are connected horizontally/vertically (not diagonally).
        - The grid is completely surrounded by water.
        - There is only one island (or nothing).
        - The island doesn’t have “lakes” (water inside that isn’t connected
        to the water surrounding the island).
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:  # Found land
                perimeter += 4  # Start with max perimeter
                if i > 0 and grid[i - 1][j] == 1:  # Check top
                    perimeter -= 1
                if i < rows - 1 and grid[i + 1][j] == 1:  # Check bottom
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:  # Check left
                    perimeter -= 1
                if j < cols - 1 and grid[i][j + 1] == 1:  # Check right
                    perimeter -= 1

    return perimeter
