#!/usr/bin/python3
def minOperations(n):
    return 0


def minOperations_full(n):
    # find smallest divisor starting at 2
    # if no divisor found, it's prime number
    sd = smallest_divisor(n)
    if sd == n:
        print("{} is a prime number!".format(n))
    count = 1
    for i in range(sd, n + 1, sd):
        if i == n:
            return count
        count += 1
    return count


def smallest_divisor(n):
    for i in range(2, n):
        if n % i == 0:
            return i
    return n
