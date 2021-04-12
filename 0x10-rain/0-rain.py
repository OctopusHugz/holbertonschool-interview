#!/usr/bin/python3
""" This module creates a rain function """


def rain(walls):
    """ Calculates how much rain water is retained """
    return sum(walls[1:-1])
