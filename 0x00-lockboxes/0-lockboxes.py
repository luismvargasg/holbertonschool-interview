#!/usr/bin/python3
""" Method that determines if all the boxes can be opened. """


def canUnlockAll(boxes):
    """ Method that seeks for keys inside boxes to open other boxes

    Args:
        boxes: list of lists "locked boxes" Each box is numbered sequentially
        from 0 to n - 1 and each box may contain keys to the other boxes.

    Return:
        True if all boxes can be opened, else return False.
    """
    keys = {0}
    for box in range(0, len(boxes) - 1):
        if box in keys:
            keys.update(boxes[box])
            for key in boxes[box]:
                if key < len(boxes) - 1:
                    keys.update(boxes[key])
        else:
            return False
    return True
