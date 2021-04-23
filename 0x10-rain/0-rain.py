#!/usr/bin/python3
""" This module creates a rain function """


def rain(walls):
    """ Calculates how much rain water is retained """
    total_rain = 0
    for i in range(len(walls)):
        index = walls[i]
        if i > 0:
            left_list = walls[0:i]
            left_wall_height = max(left_list)
        else:
            left_wall_height = index
        if i < len(walls):
            right_list = walls[i:]
            right_wall_height = max(right_list)
        else:
            right_wall_height = index
        total_rain += (min(left_wall_height, right_wall_height) - index)
    return total_rain
