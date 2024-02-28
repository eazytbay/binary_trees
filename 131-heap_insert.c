#include "binary_trees.h"

/**
 * heap_insert - This function  inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *tree, *fr, *flip, int size, br, und, x, level, ephem;
if (!root)
return (NULL);
if (!(*root))
return (*root = binary_tree_node(NULL, value));
tree = *root, size = binary_tree_size(tree), br = size, level = 0, und = 1;
while (br >= und)
{
br -= und;
und *= 2;
level++;
}
x = 1 << (level - 1);
while (x != 1)
{
if (br & x)
tree = tree->right;
else
tree = tree->left;
x >>= 1;
}
fr = binary_tree_node(tree, value);
if (br & 1)
tree->right = fr;
else
tree->left = fr;
flip = fr;
while (flip->parent && (flip->n > flip->parent->n))
{
ephem = flip->n;
flip->n = flip->parent->n;
flip->parent->n = ephem;
fr = fr->parent;
flip = flip->parent;
}
return (fr);
}

/**
 * binary_tree_size - A function that measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (!tree)
return (0);
size_t left_size = binary_tree_size(tree->left);
size_t right_size = binary_tree_size(tree->right);

return (left_size + right_size + 1);
}
