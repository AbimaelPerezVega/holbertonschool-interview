#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the elements of an array from a given range
 * @array: The array to print
 * @low: The starting index
 * @high: The ending index
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i != high)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for the first occurrence of a value
 * @array: Pointer to the first element of the array
 * @low: The starting index of the current search range
 * @high: The ending index of the current search range
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of value, or -1 if not found
 */
int recursive_search(int *array, size_t low, size_t high, int value)
{
    size_t mid;
 
    if (low > high)
        return (-1);
 
    print_array(array, low, high);

    mid = low + (high - low) / 2;
 
    if (array[mid] == value)
    {
        int left = recursive_search(array, low, mid - 1, value); /* ✅ check left */
        if (left != -1)
            return (left);
        return ((int)mid); /* ✅ only return mid if no earlier value */
    }
    else if (array[mid] > value)
    {
        return (recursive_search(array, low, mid - 1, value));
    }
    else
    {
        return (recursive_search(array, mid + 1, high, value));
    }
}
 
/**
 * advanced_binary - Searches for a value in a sorted array using advanced binary search
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
