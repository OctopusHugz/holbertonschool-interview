#!/usr/bin/python3
"""This module returns minimum operations"""


def minOperations(n):
    """Returns minimum operations to result in n characters in a text file"""
    factors_list = []
    step = 2
    while step * step <= n:
        while n % step == 0:
            n /= step
            factors_list.append(int(step))
        step += 1
    if n > 1:
        factors_list.append(int(n))
    return sum(factors_list)
