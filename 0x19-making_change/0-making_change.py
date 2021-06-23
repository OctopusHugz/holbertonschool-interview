#!/usr/bin/python3
""" This module implements a makeChabge function """


def makeChange(coins, total):
    """ Determines the fewest number of coins needed to meet given total """
    if total <= 0:
        return 0
    change = 0
    num_coins = 0
    index = 0
    # Sort coins highest to lowest
    sorted_coins = sorted(coins, reverse=True)
    while(change < total and index < len(coins)):
        if (change + sorted_coins[index] <= total):
            change += sorted_coins[index]
            num_coins += 1
        else:
            index += 1
    if change == total:
        return num_coins
    return -1
