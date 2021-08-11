#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste.
"""


def minOperations(n):
    """
    Method that calculates the fewest number of operations needed to result in
    exactly n H characters in the file.

    Args:
        n: integer (number of characters to reach)

    Returns:
        An integer (the minimum number of operations to reach n)
    """
    if type(n) != int or n <= 1:
        return 0

    copied_chars = 1
    printed_chars = 2
    ops = 2

    while printed_chars < n:
        if n % pasted_chars == 0:
            copied_chars = printed_chars
            ops += 1
        printed_chars += copied_chars
        ops += 1

    return ops
