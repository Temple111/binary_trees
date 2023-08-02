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
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves in
 *
 * Description: A NULL pointer is not a leaf
 *
 * Return: number of leaves in a binary tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lft, rgt;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_a_leaf(tree))
		return (1);
	lft = binary_tree_leaves(tree->left);
	rgt = binary_tree_leaves(tree->right);
	return (lft + rgt);
}
