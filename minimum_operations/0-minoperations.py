#!/usr/bin/python3
def minOperations(n):
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
