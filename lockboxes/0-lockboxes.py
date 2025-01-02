def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    
    Args:
        boxes (list of lists): Each sublist represents a box and contains keys to other boxes.
    
    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    unlocked = set([0])  # Start with the first box unlocked
    keys = set(boxes[0])  # Start with the keys from the first box

    while keys:
        key = keys.pop()
        if key not in unlocked and 0 <= key < len(boxes):
            unlocked.add(key)
            keys.update(boxes[key])  # Add keys from the newly unlocked box

    return len(unlocked) == len(boxes)
