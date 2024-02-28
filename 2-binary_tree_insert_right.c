#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node_2 - This function creates a binary tree node
 * @parent: parent of the node to create
 * @value: value to store in new node
 *
 * Return: points to the new node
 */
binary_tree_t *binary_tree_node_2(binary_tree_t *parent, int value)
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
 * binary_tree_insert_right - A function that inserts a node as the
 * right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Description: If parent already has a right-child, the new node must take its
 * place and the old right-child must be set as the right-child of the new node
 *
 * Return: pointer to the created node, or NULL on failure if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *r_c;

	if (parent == NULL)
		return (NULL);
	r_c = binary_tree_node_2(parent, value);
	if (r_c == NULL)
		return (NULL);
	r_c->right = parent->right;
	if (r_c->right != NULL)
		r_c->right->parent = r_c;
	parent->right = r_c;
	return (r_c);
}
