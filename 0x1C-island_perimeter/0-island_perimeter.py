#!/usr/bin/python3
"""This module creates the island_perimeter function"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in grid"""
    sides = 0
    for x, row in enumerate(grid):
        for y, num in enumerate(row):
            if num == 1:
                if x == 0:
                    sides += 1
                if x > 0:
                    if grid[x - 1][y] == 0:
                        sides += 1
                if x < len(grid) - 1:
                    if grid[x + 1][y] == 0:
                        sides += 1
                if x == len(grid) - 1:
                    sides += 1
                if y == 0:
                    sides += 1
                if y > 0:
                    if grid[x][y - 1] == 0:
                        sides += 1
                if y < len(row) - 1:
                    if grid[x][y + 1] == 0:
                        sides += 1
                if y == len(row) - 1:
                    sides += 1
    return sides
