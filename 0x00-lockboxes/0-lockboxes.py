#!/usr/bin/python3
def canUnlockAll(boxes):
    """This function checks to see if all lockboxes can be unlocked"""
    unlocked = []
    keys = {}
    index = 0
    if 1 not in boxes[0]:
        return False
    for box in boxes:
        for key in box:
            if index + 1 == key:
                unlocked.append(True)
            if key not in keys and key >= 1:
                try:
                    keys[index].append(key)
                except KeyError:
                    keys[index] = [key]
        index += 1
    if unlocked.count(True) == len(boxes) - 1:
        return True
    return False
