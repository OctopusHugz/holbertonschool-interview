#!/usr/bin/python3
"""This module returns minimum operations"""


def minOperations(n):
    """Returns minimum operations to result in n characters in a text file"""
    # find smallest divisor starting at 2
    # if no divisor found, it's prime number
    if n < 1:
        return 0
    sd = smallest_divisor(n)
    if sd == n:
        # prime number
        return sd
    count = 1
    for i in range(sd, n + 1, sd):
        if i == n:
            return count
        count += 1
    return count


def smallest_divisor(n):
    """Returns smallest divisor"""
    for i in range(2, n):
        if n % i == 0:
            return i
    return n
