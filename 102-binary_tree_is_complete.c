#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
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

	if (tree == NULL)
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
		return (1);
	a = tree->left;
	b = tree->right;
	if (binary_tree_is_leaf(tree))
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
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_hgt, r_hgt;
	binary_tree_t *a, *b;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	a = tree->left;
	b = tree->right;
	l_hgt = binary_tree_height(a);
	r_hgt = binary_tree_height(b);
	if (l_hgt == r_hgt)
	{
		if (binary_tree_is_perfect(a) && binary_tree_is_complete(b))
			return (1);
	}
	else if (l_hgt == r_hgt + 1)
	{
		if (binary_tree_is_complete(a) && binary_tree_is_perfect(b))
			return (1);
	}
	return (0);
}
