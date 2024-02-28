#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - This function goes through a binary tree
 * cheking ropt as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int check_max(const binary_tree_t *tree)
{
	int ephem1 = 1, ephem2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		ephem1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		ephem2 = check_max(tree->right);
	}
	return (ephem1 && ephem2);
}
/**
 * binary_tree_is_heap - This function checks whether a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int ephem;

	if (!tree)
		return (0);

	ephem = binary_tree_is_complete(tree);
	if (!ephem)
		return (0);
	return (check_max(tree));
}
