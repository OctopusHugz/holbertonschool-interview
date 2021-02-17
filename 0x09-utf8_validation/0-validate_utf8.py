#!/usr/bin/python3
"""This module contains a method for determining if data is in UTF-8 format"""


def validUTF8(data):
    """Determines if given data set represents valid UTF-8 encoding and returns
    true if data set is valid UTF-8, otherwise returns false"""
    skip = 0
    for i in range(len(data)):
        if skip > 0:
            skip -= 1
            continue
        num = data[i]
        if num >= 0 and num <= 127:
            continue
        else:
            # Ensure multi-byte sequences no greater than 4 bytes
            if num >= 194 and num <= 223:
                # 2 byte character
                next_set = data[i+1:i+2]
            elif num >= 224 and num <= 239:
                # 3 byte character
                next_set = data[i+1:i+3]
            elif num >= 242 and num <= 247:
                # 4 byte character
                next_set = data[i+1:i+4]
            else:
                return False
            # First byte correct, check rest of bytes in next_set for 128-191
            for number in next_set:
                if number < 128 or number > 191:
                    return False
            skip = len(next_set)
    return True
