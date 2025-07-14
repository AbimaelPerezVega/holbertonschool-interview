#include "binary_trees.h"

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The greater of the two
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + max(
		binary_tree_height(tree->left),
		binary_tree_height(tree->right)));
}

/**
 * is_bst - Checks if a tree is a valid BST
 * @tree: Pointer to the node
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if true, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = (int)binary_tree_height(tree->left);
	right_height = (int)binary_tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right));
}
