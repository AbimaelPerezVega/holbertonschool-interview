#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Gets the maximum number in an array
 * @array: The array of integers
 * @size: Size of the array
 * Return: The maximum number
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts the array using counting sort based on digit
 * @array: The array to sort
 * @size: Size of the array
 * @exp: The current exponent (digit place)
 */
void counting_sort(int *array, size_t size, int exp)
{
	int count[10] = {0};
	int *output;
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array using the Radix Sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
