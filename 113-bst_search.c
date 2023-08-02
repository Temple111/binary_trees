#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary search tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equal to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *cmp;

	cmp = (bst_t *)tree;
	while (cmp)
	{
		if (cmp->n == value)
			return (cmp);
		if (cmp->n < value)
			cmp = cmp->right;
		else
			cmp = cmp->left;
	}
	return (NULL);
}
