#!/usr/bin/python3
"""This module implements the nqueens algorithm"""
from sys import argv
if len(argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    n = int(argv[1])
except ValueError:
    print("N must be a number")
    exit(1)
else:
    if n < 4:
        print("N must be at least 4")
        exit(1)
