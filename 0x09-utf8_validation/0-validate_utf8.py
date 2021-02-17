#!/usr/bin/python3
"""This module contains a method for determining if data is in UTF-8 format"""


def validUTF8(data):
    """Determines if given data set represents valid UTF-8 encoding and returns
    true if data set is valid UTF-8, otherwise returns false"""
    for i in range(len(data)):
        num = data[i]
        if num >= 0 and num <= 127:
            continue
        else:
            if num >= 194 and num <= 253:
                # Need to dynamically determine length in bytes (not always 3!)
                next_three = data[i+1:i+4]
                # Check next 3 integers are between 128-191
                for number in next_three:
                    if number < 128 or number > 191:
                        return False
            else:
                return False
    return True
