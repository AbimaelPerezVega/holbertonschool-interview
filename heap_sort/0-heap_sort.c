#include "sort.h"
#include <stdio.h>

/**
 * heapify - Adjusts the heap to satisfy the heap property
 * @array: Array to heapify
 * @size: Size of the heap
 * @index: Root index of the subtree to heapify
 */
void heapify(int *array, size_t size, size_t index)
{
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != index)
    {
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        print_array(array, size);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--)
    {
        // Move current root to end
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        print_array(array, size);

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}
