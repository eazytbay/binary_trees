#include "binary_trees.h"

/**
 * bst_search - A function that searches for a value in a binary search tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equal to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
bst_t *ephem;

for (ephem = (bst_t *)tree; ephem != NULL; )
{
if (ephem->n == value)
return (ephem);
if (ephem->n < value)
ephem = ephem->right;
else
ephem = ephem->left;
}
return (NULL);
}

