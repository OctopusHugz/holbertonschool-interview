#!/usr/bin/python3
def canUnlockAll(boxes):
    """This function checks to see if all lockboxes can be unlocked"""
    unlocked = {0: True}
    keys = []
    index = 0
    for box in boxes:
        for key in box:
            if key not in keys:
                keys.append(key)
        if index + 1 in keys:
            unlocked.update({index + 1: True})
        else:
            for k in keys:
                if k == index + 1 or index + 1 in boxes[k]:
                    unlocked.update({index + 1: True})
                    break
        index += 1
    if len(unlocked.keys()) == len(boxes):
        return True
    return False
