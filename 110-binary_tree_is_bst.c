#include "binary_trees.h"
#include <stdio.h>

/**
 * greater_than_val - check if all values in the tree are greater than a value
 * @tree: pointer to the tree to check
 * @va: value to check against
 *
 * Return: 1 if true, 0 if false
 */
int greater_than_val(const binary_tree_t *tree, int va)
{
	int a, b;

	if (tree == NULL)
		return (1);
	if (tree->n > va)
	{
		a = greater_than_val(tree->left, va);
		b = greater_than_val(tree->right, va);
		if (a && b)
			return (1);
	}
	return (0);
}

/**
 * less_than_val - check if all values in the tree are less than a
 *                 specific value
 * @tree: pointer to the tree to check
 * @va: value to check against
 *
 * Return: 1 if true, 0 if false
 */
int less_than_val(const binary_tree_t *tree, int va)
{
	int a, b;

	if (tree == NULL)
		return (1);
	if (tree->n < va)
	{
		a = less_than_val(tree->left, va);
		b = less_than_val(tree->right, va);
		if (a && b)
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (less_than_val(tree->left, tree->n) && greater_than_val(tree->right,
				tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);
		}

	}
	return (0);
}
