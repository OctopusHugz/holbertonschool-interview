#!/usr/bin/python3
"""This module contains a method for determining if data is in UTF-8 format"""


def validUTF8(data):
    """Determines if given data set represents valid UTF-8 encoding and returns
    true if data set is valid UTF-8, otherwise returns false"""
    # A character in UTF-8 can be 1 to 4 bytes long
    # The data set can contain multiple characters
    # The data will be represented by a list of integers
    # Each integer represents 1 byte of data, therefore you only need to
    # handle the 8 least significant bits of each integer
    for num in data:
        if num > 255:
            return False
    return True
