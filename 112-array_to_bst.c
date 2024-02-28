#include "binary_trees.h"

/**
 * array_to_bst - This function builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Description: If a value of the array already exists, this value is ignored
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *found = NULL;
	size_t x;

	for (x = 0; x < size; x++)
	{
		bst_insert(&found, array[x]);
	}
	return (found);
}
