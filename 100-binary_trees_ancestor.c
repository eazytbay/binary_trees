#include "binary_trees.h"

/**
 * binary_trees_ancestor - A function that locates the least common 
 * ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *ephem;

if (first == NULL || second == NULL)
return (NULL);

ephem = (binary_tree_t *)second;
for (; first != NULL; first = first->parent)
{
for (; second != NULL; second = second->parent)
{
if (first == second)
return ((binary_tree_t *)first);
}
second = ephem;
}
return (NULL);
}

