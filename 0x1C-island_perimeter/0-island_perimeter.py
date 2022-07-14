#!/usr/bin/python3
"""
Function that returns the perimeter of the island described in grid.
"""


def island_perimeter(grid):
    """
    - Grid is a list of list of integers:
        0 represents water.
        1 represents land.
        Each cell is square, with a side length of 1.
        Cells are connected horizontally/vertically (not diagonally).
        Grid is rectangular, with its width and height not exceeding 100.
    - The grid is completely surrounded by water.
    - There is only one island (or nothing).
    - The island doesn't have “lakes” (water inside that isn't connected to the water
      surrounding the island).
    """
    perimeter = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                if x == 0 or grid[x - 1][y] == 0:
                    perimeter += 1
                if y == 0 or grid[x][y - 1] == 0:
                    perimeter += 1
                if x == len(grid) - 1 or grid[x + 1][y] == 0:
                    perimeter += 1
                if y == len(grid[x]) - 1 or grid[x][y + 1] == 0:
                    perimeter += 1
    return (perimeter)
