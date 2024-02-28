#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf -This function checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - This function measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_is_perfect - This function checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *x, *y;

	if (tree == NULL)
		return (1);
	x = tree->left;
	y = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (x == NULL || y == NULL)
		return (0);
	if (binary_tree_height(x) == binary_tree_height(y))
	{
		if (binary_tree_is_perfect(x) && binary_tree_is_perfect(y))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete - This function checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t x_height, y_height;
	binary_tree_t *x, *y;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	x = tree->left;
	y = tree->right;
	x_height = binary_tree_height(x);
	y_height = binary_tree_height(y);
	if (x_height == y_height)
	{
		if (binary_tree_is_perfect(x) && binary_tree_is_complete(y))
			return (1);
	}
	else if (x_height == y_height + 1)
	{
		if (binary_tree_is_complete(x) && binary_tree_is_perfect(y))
			return (1);
	}
	return (0);
}
