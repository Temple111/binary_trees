#include "binary_trees.h"

/**
 * binary_tree_is_a_leaf - checks if a node is a leaf
 * @nd: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *nd)
{
	if (nd != NULL && nd->left == NULL && nd->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, otherwise 0. If tree is NULL, return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int lft, rgt;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	lft = binary_tree_is_full(tree->left);
	rgt = binary_tree_is_full(tree->right);
	if (lft == 0 || rgt == 0)
		return (0);
	return (1);
}
