#!/usr/bin/python3
"""
Method that determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Method that determines if a given data set represents
    a valid UTF-8 encoding.

    Returns: True if data is a valid UTF-8 encoding, else return False.
    """
    n_bytes = 0

    for n in data:
        byte = format(n, '#010b')[-8:]
        if n_bytes == 0:
            if byte[0] == '1':
                n_bytes = len(byte.split('0')[0])
            if n_bytes > 4 or n_bytes == 1:
                return False
            if n_bytes == 0:
                continue
        else:
            if not byte.startswith('10'):
                return False
        n_bytes -= 1

    if n_bytes != 0:
        return False
    return True
