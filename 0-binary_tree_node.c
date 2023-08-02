#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parnt of the node to create
 * @value: value to store in new node
 *
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nw_nd;

	nw_nd = malloc(sizeof(binary_tree_t));
	if (nw_nd == NULL)
		return (NULL);
	nw_nd->parent = parent;
	nw_nd->n = value;
	nw_nd->left = nw_nd->right = NULL;
	return (nw_nd);
}
