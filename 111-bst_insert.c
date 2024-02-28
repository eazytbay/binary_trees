#include "binary_trees.h"

/**
 * bst_insert - A function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Description: If the address stored in tree is NULL, the created node must
 * become the root node. If the value is already present in the tree, it must
 * be ignored
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *ephem;
if (tree)
{
if (*tree == NULL)
{
*tree = (bst_t *)binary_tree_node(NULL, value);
return (*tree);
}
for (ephem = *tree; ephem != NULL; )
{
if (ephem->n == value)
break;
if (ephem->n > value)
{
if (!ephem->left)
{
ephem->left = (bst_t *)binary_tree_node(ephem, value);
return (ephem->left);
}
ephem = ephem->left;
}
else if (ephem->n < value)
{
if (!ephem->right)
{
ephem->right = (bst_t *)binary_tree_node(ephem, value);
return (ephem->right);
}
ephem = ephem->right;
}
}
}
return (NULL);
}
