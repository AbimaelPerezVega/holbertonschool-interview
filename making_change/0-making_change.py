#!/usr/bin/python3
"""
This module contains the makeChange function.
"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given total.

    Args:
        coins (list): List of coin denominations.
        total (int): The target amount.

    Returns:
        int: Minimum number of coins needed
        to meet total, or -1 if not possible.
    """
    if total <= 0:
        return 0

    # Initialize an array to store the minimum number of coins for each amount
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # 0 coins are needed to make total 0

    for coin in coins:
        for x in range(coin, total + 1):
            dp[x] = min(dp[x], dp[x - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
