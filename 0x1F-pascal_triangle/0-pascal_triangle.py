#!/usr/bin/python3
""" This module implements a pascal triangle algorithm """


def pascal_triangle(n):
    """ Returns a list of lists of integers representing the Pascal's triangle
    of n """
    triangle = []
    for num in range(n):
        row = []
        for val in range(num + 1):
            if val == 0 or val == num:
                row.append(1)
                continue
            row.append(triangle[num - 1][val - 1] + triangle[num - 1][val])
        triangle.append(row)
    return triangle
