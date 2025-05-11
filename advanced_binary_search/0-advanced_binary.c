#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search_recursive - Recursively searches for the first occurrence
 *                           of value and prints each subarray examined.
 * @array: Pointer to the original array
 * @left:  Left index of the current subarray
 * @right: Right index of the current subarray
 * @value: The value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
static int binary_search_recursive(int *array, size_t left,
	size_t right, int value)
{
	size_t mid, i;

	if (left > right)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid > left && array[mid - 1] == value)
			return (binary_search_recursive(array, left, mid, value));
		return ((int)mid);
	}
	else if (array[mid] < value)
	{
		return (binary_search_recursive(array, mid + 1, right, value));
	}
	else
	{
		return (binary_search_recursive(array, left, mid, value));
	}
}

/**
 * advanced_binary - Searches for the first occurrence of value
 *                   in a sorted array.
 * @array: Pointer to the first element of the array to search in
 * @size:  Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found or array
 *         is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
