#include "binary_trees.h"

/**
 * create_tree - This function creates an AVL tree recursively
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t center;

	if (size == 0)
		return;

	center = (size / 2);
	center = (size % 2 == 0) ? center - 1 : center;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[center]);
		create_tree(&((*node)->left), array, center, 1);
		create_tree(&((*node)->left), array + center + 1, (size - 1 - center), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[center]);
		create_tree(&((*node)->right), array, center, 1);
		create_tree(&((*node)->right), array + center + 1, (size - 1 - center), 2);
	}
}

/**
 * sorted_array_to_avl - This function creates root node and
 * calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *found;
	size_t center;

	found = NULL;

	if (size == 0)
		return (NULL);

	center = (size / 2);

	center = (size % 2 == 0) ? center - 1 : center;

	found = binary_tree_node(found, array[center]);

	create_tree(&found, array, center, 1);
	create_tree(&found, array + center + 1, (size - 1 - center), 2);

	return (found);
}
