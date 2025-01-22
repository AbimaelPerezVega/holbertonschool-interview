#!/usr/bin/python3
"""
This module provides a function to calculate the minimum number of operations
needed to achieve exactly `n` 'H'
characters in a text file starting with a single 'H'.

Operations allowed:
1. Copy All: Copies all characters currently in the file.
2. Paste: Appends the copied content to the end of the file.

The function `minOperations` determines the minimum operations needed
using a strategy based on prime factorization.

Functions:
    minOperations(n): Returns the minimum number of operations required.
"""


def minOperations(n):
    """
    Calculates the minimum number of operations
    needed to result in exactly n 'H' characters.

    Parameters:
        n (int): The desired number of 'H' characters.

    Returns:
        int: The minimum number of operations required,
        or 0 if n is impossible to achieve.
    """
    if n <= 1:
        return 0  # Impossible to achieve if n <= 1

    operations = 0
    divisor = 2  # Start checking divisors from 2

    while n > 1:
        while n % divisor == 0:  # While divisible, reduce n
            operations += divisor
            n //= divisor
        divisor += 1  # Check next potential divisor

    return operations
