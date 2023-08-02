#include "binary_trees.h"

/**
 * binary_tree_is_a_leaf - checks if a node is a leaf
 * @nd: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_a_leaf(const binary_tree_t *nd)
{
	if (nd != NULL && nd->left == NULL && nd->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the nodes in
 *
 * Description: A NULL pointer is not a node
 *
 * Return: number of nodes with at least 1 child in a binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t lft, rgt;

	if (tree == NULL || binary_tree_is_a_leaf(tree))
		return (0);
	lft = binary_tree_nodes(tree->left);
	rgt = binary_tree_nodes(tree->right);
	return (1 + lft + rgt);
}
