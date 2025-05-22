#include "binary_trees.h"

/**
 * heapify_down - Moves a node down the
 * heap until it is in the correct position.
 * @node: Pointer to the node to heapify down.
 */
void heapify_down(heap_t *node)
{
	heap_t *max_child = NULL;
	int temp;

	while (node)
	{
		max_child = node;

		if (node->left && node->left->n > max_child->n)
			max_child = node->left;
		if (node->right && node->right->n > max_child->n)
			max_child = node->right;

		if (max_child == node)
			break;

		temp = node->n;
		node->n = max_child->n;
		max_child->n = temp;

		node = max_child;
	}
}

/**
 * find_last_node - Finds the last node in level-order traversal.
 * @root: Pointer to the root node.
 * Return: Pointer to the last node.
 */
heap_t *find_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		root = queue[front++];
		if (root->left)
			queue[rear++] = root->left;
		if (root->right)
			queue[rear++] = root->right;
	}

	return (root);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *parent;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	/* If it's a single node */
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = find_last_node(*root);

	/* Replace root's value with last node's value */
	(*root)->n = last->n;

	/* Remove last node */
	parent = last->parent;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;
	free(last);

	/* Rebuild heap */
	heapify_down(*root);

	return (value);
}
