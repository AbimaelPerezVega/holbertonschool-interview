#ifndef LIST_H
#define LIST_H

/**
 * struct List - Doubly linked list node
 * @str:  (malloc'ed) string
 * @prev: Pointer to previous node
 * @next: Pointer to next node
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
