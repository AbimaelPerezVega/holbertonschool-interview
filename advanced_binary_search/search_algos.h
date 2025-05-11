#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

/* 
 * advanced_binary - Searches for the first occurrence of value in a sorted array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */