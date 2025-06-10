#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into a sorted array
 * @array: Original array
 * @temp: Temporary array for merging
 * @left: Start index of left subarray
 * @mid: Middle index, start of right subarray
 * @right: End index (exclusive)
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = left;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively sorts array with merge sort
 * @array: The array to sort
 * @temp: Temporary array used for merging
 * @left: Starting index (inclusive)
 * @right: Ending index (exclusive)
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = (left + right) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: The array to sort
 * @size: Number of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}
