#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: Starting index of left subarray
 * @mid: Middle index
 * @right: Ending index of right subarray
 * @temp: Temporary array to store merged subarrays
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
    int i = left, j = mid + 1, k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, mid - left + 1);
    printf("[right]: ");
    print_array(array + mid + 1, right - mid);

    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= right)
        temp[k++] = array[j++];

    for (i = 0; i < k; i++)
        array[left + i] = temp[i];

    printf("[Done]: ");
    print_array(array + left, right - left + 1);
}

/**
 * merge_sort_helper - Helper function for merge sort
 * @array: The array to be sorted
 * @left: Starting index
 * @right: Ending index
 * @temp: Temporary array for merging
 */
void merge_sort_helper(int *array, int left, int right, int *temp)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_helper(array, left, mid, temp);
        merge_sort_helper(array, mid + 1, right, temp);
        merge(array, left, mid, right, temp);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    merge_sort_helper(array, 0, size - 1, temp);
    free(temp);
}
