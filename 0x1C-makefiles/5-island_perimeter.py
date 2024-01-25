#!/usr/bin/python3

def island_perimeter(grid):
    """
    Calculates the perimeter of an island defined in a grid.
    0 represents water, 1 represents land. Cells are connected
    horizontally/vertically (not diagonally).

    :param grid: List of lists of integers representing the grid.
    :return: The perimeter of the island.
    """
    rows = len(grid)
    cols = len(grid[0]) if rows else 0
    perimeter = 0

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                # Check all four sides for water or grid edge
                # Up
                if r == 0 or grid[r - 1][c] == 0:
                    perimeter += 1
                # Down
                if r == rows - 1 or grid[r + 1][c] == 0:
                    perimeter += 1
                # Left
                if c == 0 or grid[r][c - 1] == 0:
                    perimeter += 1
                # Right
                if c == cols - 1 or grid[r][c + 1] == 0:
                    perimeter += 1

    return perimeter
