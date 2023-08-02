#include "binary_trees.h"
#include "limits.h"

size_t hgt(const binary_tree_t *tree);
int is_avl_helper_0(const binary_tree_t *tree, int low, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * hgt - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t hgt(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t a = 0, b = 0;

		a = tree->left ? 1 + hgt(tree->left) : 1;
		b = tree->right ? 1 + hgt(tree->right) : 1;
		return ((a > b) ? a : b);
	}
	return (0);
}

/**
 * is_avl_helper_0 - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper_0(const binary_tree_t *tree, int low, int hi)
{
	size_t l_hgt, r_hgt, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > hi)
			return (0);
		l_hgt = hgt(tree->left);
		r_hgt = hgt(tree->right);
		diff = l_hgt > r_hgt ? l_hgt - r_hgt : r_hgt - l_hgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper_0(tree->left, low, tree->n - 1) &&
			is_avl_helper_0(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper_0(tree, INT_MIN, INT_MAX));
}
