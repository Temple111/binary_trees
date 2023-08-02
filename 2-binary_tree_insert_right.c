#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node_2 - creates a binary tree node
 * @parent: parnt of the node to create
 * @value: value to store in new node
 *
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node_2(binary_tree_t *parent, int value)
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

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Description: If parent already has a right-child, the new node must take its
 * place and the old right-child must be set as the right-child of the new node
 *
 * Return: pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rgt_chld;

	if (parent == NULL)
		return (NULL);
	rgt_chld = binary_tree_node_2(parent, value);
	if (rgt_chld == NULL)
		return (NULL);
	rgt_chld->right = parent->right;
	if (rgt_chld->right != NULL)
		rgt_chld->right->parent = rgt_chld;
	parent->right = rgt_chld;
	return (rgt_chld);
}
