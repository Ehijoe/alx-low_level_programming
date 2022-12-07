#!/usr/bin/python3
"""Determine the perimeter of an island."""


def count_crossings(grid, i, j):
    """Check if the cursor has moved between from water and land."""
    crossings = 0

    # Check vertical crossings
    if i == 0:
        crossings += grid[i][j]
    else:
        if grid[i - 1][j] != grid[i][j]:
            crossings += 1

    # Check horizontal crossings
    if j == 0:
        crossings += grid[i][j]
    else:
        if grid[i][j - 1] != grid[i][j]:
            crossings += 1
    return crossings


def island_perimeter(grid):
    """Return the perimeter of the island."""
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            perimeter += count_crossings(grid, i, j)
        perimeter += grid[i][-1]
    for j in range(len(grid[0])):
        perimeter += grid[-1][j]
    return perimeter
