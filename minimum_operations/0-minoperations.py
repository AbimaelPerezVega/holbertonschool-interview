def minOperations(n):
    if n <= 0:
        return 0
    
    operations = 0
    current_length = 1  # Starting with 1 character 'H'
    clipboard = 0  # Initially clipboard is empty
    
    while current_length < n:
        if n % current_length == 0:
            clipboard = current_length
        operations += 1
        current_length += clipboard
    
    return operations
