#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Allocates and initializes a new node
 * @str: The string to duplicate into the new node
 * Return: Pointer to the new node, or NULL on failure
 */
static List *create_node(char *str)
{
    List *new_node;
    char *dup_str;

    new_node = malloc(sizeof(List));
    if (!new_node)
        return (NULL);

    dup_str = strdup(str);
    if (!dup_str)
    {
        free(new_node);
        return (NULL);
    }

    new_node->str = dup_str;
    new_node->prev = new_node->next = NULL;

    return (new_node);
}

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 * @list: A pointer to the pointer of the list head
 * @str: The string to duplicate into the new node
 * Return: Pointer to the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
    List *new_node = create_node(str);
    List *last;

    if (!new_node)
        return (NULL);

    if (!list || !(*list))
    {
        new_node->next = new_node->prev = new_node;
        *list = new_node;
    }
    else
    {
        last = (*list)->prev;
        last->next = new_node;
        new_node->prev = last;
        new_node->next = *list;
        (*list)->prev = new_node;
    }

    return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular list
 * @list: A pointer to the pointer of the list head
 * @str: The string to duplicate into the new node
 * Return: Pointer to the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
    List *new_node = add_node_end(list, str);

    if (new_node)
        *list = new_node;

    return (new_node);
}
