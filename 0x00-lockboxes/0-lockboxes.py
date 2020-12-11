#!/usr/bin/python3
# global count
# count = 0


# def canUnlockAll(boxes):
#     """This function checks to see if all lockboxes can be unlocked"""
#     unlocked = []
#     if len(boxes) <= 1:
#         return True
#     if len(boxes[0]) == 0:
#         return False

#     def unlocker(box, count):
#         if box not in unlocked and box < len(boxes):
#             unlocked.append(box)
#             count += 1
#             for key in boxes[box]:
#                 print("Count is: {:d}".format(count))
#                 unlocker(key, count)

#     unlocker(0, count)
#     if len(unlocked) == len(boxes):
#         return True
#     return False


def canUnlockAll(boxes):
    """This function checks to see if all lockboxes can be unlocked"""
    unlocked = {0: True}
    keys = []
    index = 0
    if len(boxes) <= 1:
        return True
    if len(boxes[0]) == 0:
        return False
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
