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
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lft, rgt;

	if (tree == NULL || binary_tree_is_a_leaf(tree))
		return (0);
	lft = binary_tree_height(tree->left);
	rgt = binary_tree_height(tree->right);
	if (lft >= rgt)
		return (1 + lft);
	return (1 + rgt);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *a, *b;

	if (tree == NULL)
		return (0);
	a = tree->left;
	b = tree->right;
	if (binary_tree_is_a_leaf(tree))
		return (1);
	if (a == NULL || b == NULL)
		return (0);
	if (binary_tree_height(a) == binary_tree_height(b))
	{
		if (binary_tree_is_perfect(a) && binary_tree_is_perfect(b))
			return (1);
	}
	return (0);
}
