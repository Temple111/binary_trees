#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node_1 - creates a binary tree node
 * @parent: parnt of the node to create
 * @value: value to store in new node
 *
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node_1(binary_tree_t *parent, int value)
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
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Description: If parent already has a left-child, the new node must take its
 * place, and the old left-child must be set as the left-child of the new node.
 *
 * Return: pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *lft_chld;

	if (parent == NULL)
		return (NULL);
	lft_chld = binary_tree_node_1(parent, value);
	if (lft_chld == NULL)
		return (NULL);
	lft_chld->left = parent->left;
	if (lft_chld->left != NULL)
		lft_chld->left->parent = lft_chld;
	parent->left = lft_chld;
	return (lft_chld);
}
