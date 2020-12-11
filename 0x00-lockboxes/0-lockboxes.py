#!/usr/bin/python3
def canUnlockAll(boxes):
    """This function checks to see if all lockboxes can be unlocked"""
    unlocked = []
    if 1 not in boxes[0]:
        return False

    def unlocker(box):
        if box not in unlocked:
            unlocked.append(box)
            # print(unlocked)
            try:
                for key in boxes[box]:
                    # print("Running unlocker({:d})".format(box))
                    unlocker(key)
            except IndexError:
                pass

    unlocker(0)
    if len(unlocked) == len(boxes):
        return True
    return False
