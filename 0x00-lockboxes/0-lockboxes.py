#!/usr/bin/python3
"""This module implements the canUnlockAll function"""
def canUnlockAll(boxes):
    """This function checks to see if all lockboxes can be unlocked"""
    unlocked = []
    if 1 not in boxes[0] or len(boxes) == 0:
        return False

    def unlocker(box):
        if box not in unlocked and box < len(boxes):
            unlocked.append(box)
            # print(unlocked)
            for key in boxes[box]:
                # print("Running unlocker({:d})".format(box))
                unlocker(key)

    unlocker(0)
    if len(unlocked) == len(boxes):
        return True
    return False
