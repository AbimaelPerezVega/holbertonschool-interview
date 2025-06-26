#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Create a new list node
 * @str: String to duplicate
 *
 * Return: Pointer to new node or NULL on failure
 */
static List *create_node(char *str)
{
	List *node;
	char *dup;

	node = malloc(sizeof(List));
	if (!node)
		return (NULL);

	dup = strdup(str);
	if (!dup)
	{
		free(node);
		return (NULL);
	}

	node->str = dup;
	node->prev = node->next = NULL;
	return (node);
}

/**
 * add_node_end - Add a node at the end of a circular doubly list
 * @list: Address of head pointer
 * @str:  String to duplicate
 *
 * Return: Address of new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *last;

	if (!list)
		return (NULL);

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)			/* empty list → new points to itself */
	{
		new->next = new->prev = new;
		*list = new;
	}
	else
	{
		last = (*list)->prev;
		last->next = new;
		new->prev = last;
		new->next = *list;
		(*list)->prev = new;
	}
	return (new);
}

/**
 * add_node_begin - Add a node at the beginning of a circular doubly list
 * @list: Address of head pointer
 * @str:  String to duplicate
 *
 * Return: Address of new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = add_node_end(list, str);
	if (new)
		*list = new;
	return (new);
}
