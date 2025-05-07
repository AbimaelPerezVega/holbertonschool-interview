#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the current part of the array being searched.
 * @array: Pointer to the first element of the array.
 * @low: Starting index.
 * @high: Ending index.
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
 * binary_recursive - Recursively searches for the first occurrence of value.
 * @array: Pointer to the first element of the array.
 * @low: Starting index of the subarray.
 * @high: Ending index of the subarray.
 * @value: Value to search for.
 *
 * Return: Index where value is found, or -1 if not found.
 */
int binary_recursive(int *array, size_t low, size_t high, int value)
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
		else
			return (binary_recursive(array, low, mid, value));
	}
	else if (array[mid] > value)
		return (binary_recursive(array, low, mid - 1, value));
	else
		return (binary_recursive(array, mid + 1, high, value));
}

/**
 * advanced_binary - Starts a binary search to find the first occurrence of value.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index where value is found, or -1 if not found or array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
