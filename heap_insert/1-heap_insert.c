#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * enqueue - Queue management: Addition operation
 * @queue: Queue container (array of binary tree node pointers)
 * @node: Target node for enqueueing
 * @rear: Position tracker for back of queue
 *
 * Description: Handles the insertion of new nodes into the BFS queue
 */
void enqueue(heap_t **queue, heap_t *node, int *rear)
{
	queue[*rear] = node;
	(*rear)++;
}

/**
 * dequeue - Queue management: Removal operation
 * @queue: Queue container storing tree nodes
 * @front: Position tracker for front of queue
 *
 * Return: Returns node at queue front
 * Description: Extracts and returns the next node in queue sequence
 */
heap_t *dequeue(heap_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * heapify_up - Max Heap Property Maintainer
 * @node: Entry point node for upward propagation
 *
 * Return: Final resting position of processed node
 * Description: Bubble-up operation to restore heap ordering after insertion.
 *
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		/* Swap values */
		int temp = node->n;

		node->n = node->parent->n;
		node->parent->n = temp;

		/* Move up the tree */
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Max Binary Heap Insertion Handler
 * @root: Access point to heap structure
 * @value: Data to be incorporated into heap
 *
 * Return: Location of newly created node, NULL if operation fails
 * Description: Master function orchestrating the complete insertion process:
 *             1. Finds appropriate insertion point via level-order traversal
 *             2. Creates new node at target location
 *             3. Ensures max-heap property post-insertion
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *temp;
	heap_t *queue[1024]; /* BFS queue implementation */
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	/* Root initialization for empty heap */
	if (!*root)
		return (*root = binary_tree_node(NULL, value));

	/* Systematic level-by-level traversal */
	enqueue(queue, *root, &rear);

	while (front < rear)
	{
		temp = dequeue(queue, &front);

		/* Target location identification and node placement */
		if (!temp->left)
		{
			temp->left = binary_tree_node(temp, value);
			new_node = temp->left;
			break;
		}

		enqueue(queue, temp->left, &rear);

		if (!temp->right)
		{
			temp->right = binary_tree_node(temp, value);
			new_node = temp->right;
			break;
		}

		enqueue(queue, temp->right, &rear);
	}

	/* Max-heap property restoration phase */
	return (heapify_up(new_node));
}
