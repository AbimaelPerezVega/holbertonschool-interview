#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer value stored at the node
 * @index: Index of the node in the list
 * @next: Pointer to the next node in the list
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* Provided function prototypes (do NOT implement or push these) */
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/* Your implementation */
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* _SEARCH_H_ */
