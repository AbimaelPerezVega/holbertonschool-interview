#!/usr/bin/python3
"""
Module to validate UTF-8 encoding.
"""

def validUTF8(data):
    """
    Determines if a given list of integers represents a valid UTF-8 encoding.

    Args:
        data (list): A list of integers representing bytes.

    Returns:
        bool: True if data is a valid UTF-8 encoding, otherwise False.
    """

    # Mask for checking the first two bits of a byte
    MASK1 = 1 << 7  # 10000000 in binary
    MASK2 = 1 << 6  # 01000000 in binary

    # Tracks the number of bytes remaining in the current UTF-8 character
    remaining = 0

    for num in data:
        # Ensure we only check the least significant 8 bits
        num &= 0xFF

        if remaining == 0:
            # Determine the number of bytes in the current UTF-8 character
            if not (num & MASK1):  # 1-byte character (0xxxxxxx)
                continue
            elif (num & (MASK1 >> 1)) == 0:  # Invalid byte (10xxxxxx as a starting byte)
                return False
            elif (num & (MASK1 >> 2)) == 0:  # 2-byte character (110xxxxx)
                remaining = 1
            elif (num & (MASK1 >> 3)) == 0:  # 3-byte character (1110xxxx)
                remaining = 2
            elif (num & (MASK1 >> 4)) == 0:  # 4-byte character (11110xxx)
                remaining = 3
            else:  # Invalid leading byte
                return False
        else:
            # Check if the byte is a valid continuation byte (10xxxxxx)
            if not ((num & MASK1) and not (num & MASK2)):
                return False
            remaining -= 1

    # If there are remaining expected continuation bytes, the encoding is invalid
    return remaining == 0

# Testing the function with provided test cases
if __name__ == "__main__":
    data1 = [65]
    print(validUTF8(data1))  # Expected output: True
    
    data2 = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
    print(validUTF8(data2))  # Expected output: True
    
    data3 = [229, 65, 127, 256]
    print(validUTF8(data3))  # Expected output: False
