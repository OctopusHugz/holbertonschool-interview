#!/usr/bin/python3
def canUnlockAll(boxes):
    """This function checks to see if all lockboxes can be unlocked"""
    unlocked = []
    if len(boxes) == 1:
        return True
    if len(boxes) == 0 or len(boxes[0]) == 0:
        return False

    def unlocker(box):
        if box not in unlocked and box < len(boxes):
            unlocked.append(box)
            for key in boxes[box]:
                unlocker(key)

    unlocker(0)
    if len(unlocked) == len(boxes):
        return True
    return False
