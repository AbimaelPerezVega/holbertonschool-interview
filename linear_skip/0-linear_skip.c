#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start = list, *end = NULL;

	if (!list)
		return (NULL);

	/* Step through express lane */
	while (start->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->express->index, start->express->n);
		if (start->express->n >= value)
		{
			end = start->express;
			break;
		}
		start = start->express;
	}

	/* If no express match, go to end of list */
	if (!end)
	{
		end = start;
		while (end->next)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", start->index, end->index);

	/* Linear search in identified block */
	while (start && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}

	return (NULL);
}
