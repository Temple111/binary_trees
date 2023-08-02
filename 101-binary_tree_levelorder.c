#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lft, rgt;

	if (tree == NULL)
		return (0);
	lft = binary_tree_height(tree->left);
	rgt = binary_tree_height(tree->right);
	if (lft >= rgt)
		return (1 + lft);
	return (1 + rgt);
}

/**
 * binary_tree_specific_level - perform a function on a specific level
 *                              of a binary tree
 * @tree: pointer to the root of the tree
 * @le: level of the tree to perform a function on
 * @func: function to perform
 *
 * Return: void
 */
void binary_tree_specific_level(const binary_tree_t *tree, size_t le,
		void (*func)(int))
{
	if (tree == NULL)
		return;
	if (le == 1)
		func(tree->n);
	else if (le > 1)
	{
		binary_tree_specific_level(tree->left, le - 1, func);
		binary_tree_specific_level(tree->right, le - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t hgt, a;

	if (tree == NULL || func == NULL)
		return;
	hgt = binary_tree_height(tree);
	for (a = 1; a <= hgt; a++)
		binary_tree_specific_level(tree, a, func);
}
