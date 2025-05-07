#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the elements in the current search range
 * @array: The array being searched
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
 * binary_recursive - Helper function to perform binary search for first occurrence
 * @array: Pointer to the array
 * @low: Lower index
 * @high: Higher index
 * @value: Value to search for
 * Return: Index of the first occurrence or -1
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
		/* Keep searching left for first occurrence */
		return (binary_recursive(array, low, mid, value));
	}
	else if (array[mid] > value)
		return (binary_recursive(array, low, mid - 1, value));
	else
		return (binary_recursive(array, mid + 1, high, value));
}

/**
 * advanced_binary - Searches for the first occurrence of a value in a sorted array
 * @array: Pointer to the array
 * @size: Number of elements in the array
 * @value: The value to search for
 * Return: Index of the first occurrence of the value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
