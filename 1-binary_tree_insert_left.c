#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node_1 -  A function that creates a binary tree node
 * @parent: The pointer of the node to create
 * @value: The value to store in new node
 *
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node_1(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

/**
 * binary_tree_insert_left - A function that inserts a node as the
 * left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Description: If parent already has a left-child, the new node must take its
 * place, and the old left-child must be set as the left-child of the new node.
 *
 * Return: pointer to the created node, or NULL on failure if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *l_c;

	if (parent == NULL)
		return (NULL);
	l_c = binary_tree_node_1(parent, value);
	if (l_c == NULL)
		return (NULL);
	l_c->left = parent->left;
	if (l_c->left != NULL)
		l_c->left->parent = l_c;
	parent->left = l_c;
	return (l_c);
}
