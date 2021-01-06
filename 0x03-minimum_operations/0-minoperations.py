#!/usr/bin/python3
"""This module returns minimum operations"""


def minOperations(n):
    """Returns minimum operations to result in n characters in a text file"""
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
    min_ops = 0
    step = 2
    while n > 1:
        while n % step == 0:
            print("n is: {}".format(n))
            print("step is: {}".format(step))
            min_ops += step
            print("min_ops is: {}".format(min_ops))
            n /= step
            print("After division, n is: {}".format(n))
        step += 1
    return min_ops


# def smallest_divisor(n):
#     """Returns smallest divisor"""
#     for i in range(2, n):
#         if n % i == 0:
#             return (n / i)
#     return n
