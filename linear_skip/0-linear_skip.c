#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *curr;

	if (!list)
		return (NULL);

	curr = list;
	while (curr->express && curr->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->express->index, curr->express->n);
		curr = curr->express;
	}

	/* Set range for linear search */
	if (curr->express)
	{
		prev = curr;
		curr = curr->express;
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index, curr->index);
	}
	else
	{
		prev = curr;
		while (curr->next)
			curr = curr->next;
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index, curr->index);
		curr = prev;
	}

	/* Linear search in the identified block */
	while (curr && curr->index <= prev->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n == value)
			return (curr);
		curr = curr->next;
	}

	return (NULL);
}
