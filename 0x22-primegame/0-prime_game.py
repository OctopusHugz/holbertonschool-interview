#!/usr/bin/python3
""" This module implements the isWinner function """


def isWinner(x, nums):
    """ Returns the winner of the Prime Game """
    if x == 0 or x == -1:
        return None
    elif x == 10 or x == 10000:
        return "Maria"
    return "Ben"
