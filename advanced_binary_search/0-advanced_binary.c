#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the array between two indices
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
		if (i < high)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursive binary search to find first occurrence
 * @array: Array to search in
 * @low: Low index
 * @high: High index
 * @value: Value to search for
 *
 * Return: Index of first occurrence of value, or -1
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
		if (mid == low || array[mid - 1] != value)
			return ((int)mid);
		return (recursive_search(array, low, mid - 1, value));
	}
	else if (array[mid] > value)
		return (recursive_search(array, low, mid - 1, value));
	else
		return (recursive_search(array, mid + 1, high, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using advanced binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
