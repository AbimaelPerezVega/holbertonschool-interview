#include <stdio.h>

/**
 * swap - Swap two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * heapify - Turn a subtree into a max heap
 * @array: array to heapify
 * @size: size of heap
 * @root: root index of the subtree
 * @total_size: total array size (for printing)
 */
void heapify(int *array, size_t size, size_t root, size_t total_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;
	size_t i;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);

		/* Print the array after each swap */
		for (i = 0; i < total_size; i++)
		{
			if (i)
				printf(", ");
			printf("%d", array[i]);
		}
		printf("\n");

		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: Number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* Extract elements from heap one by one */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);

		/* Print the array after each swap */
		for (j = 0; j < size; j++)
		{
			if (j)
				printf(", ");
			printf("%d", array[j]);
		}
		printf("\n");

		heapify(array, i, 0, size);
	}
}
