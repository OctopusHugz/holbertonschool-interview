#!/usr/bin/python3
"""This module returns minimum operations"""


# def minOperations(n):
#     """Returns minimum operations to result in n characters in a text file"""
# find smallest divisor starting at 2
# if no divisor found, it's prime number
# if n < 1:
#     return 0
# sd = smallest_divisor(n)
# if sd == n:
#     # prime number
#     return sd
# min_ops = 1
# for i in range(sd, n + 1, sd):
#     if i == n:
#         return min_ops
#     min_ops += 1
# return min_ops
# min_ops = 0
# step = 2
# while n > 1:
#     while n % step == 0:
#         print("n is: {}".format(n))
#         print("step is: {}".format(step))
#         min_ops += step
#         print("min_ops is: {}".format(min_ops))
#         n /= step
#         print("After division, n is: {}".format(n))
#     step += 1
# return min_ops


def smallest_divisor(n):
    """Returns smallest divisor"""
    for i in range(2, n):
        if n % i == 0:
            return i
    return n


def greater_divisor(n, sd):
    """Returns False if no greater divisor, True if yes"""
    for i in range(sd + 1, n + 1):
        if n % i == 0 and n != i:
            return True
    return False


# start at 0
# as you add characters, see if your character count is a divisor of n
# if it is, copy all
# else, paste


def minOperations(n):
    """Returns minimum operations to result in n characters in a text file"""
    min_ops = 0
    step = 2
    sd = smallest_divisor(n)
    gd = greater_divisor(n, sd)
    # print("sd is: {}".format(sd))
    # print("gd is: {}".format(gd))
    for i in range(sd, n + 1, step):
        # print("i is: {}".format(i))
        # print("step is: {}".format(step))
        # print("min_ops is: {}".format(min_ops))
        if n % i == 0:
            min_ops += step
        else:
            step += 1
        # print("i is now: {}".format(i))
        # print("step is now: {}".format(step))
        # print("min_ops is now: {}".format(min_ops))
        if min_ops > 0 and n % min_ops == 0 and gd is True and min_ops != sd:
            return min_ops + (n // min_ops)
    return min_ops
