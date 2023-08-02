#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Description: If the address stored in tree is NULL, the created node must
 * become the root node. If the value is already present in the tree, it must
 * be ignored
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cmp;

	if (tree)
	{
		if (*tree == NULL)
		{
			*tree = (bst_t *)binary_tree_node(NULL, value);
			return (*tree);
		}
		cmp = *tree;
		while (cmp)
		{
			if (cmp->n == value)
				break;
			if (cmp->n > value)
			{
				if (!cmp->left)
				{
					cmp->left = (bst_t *)binary_tree_node(cmp, value);
					return (cmp->left);
				}
				cmp = cmp->left;
			}
			else if (cmp->n < value)
			{
				if (!cmp->right)
				{
					cmp->right = (bst_t *)binary_tree_node(cmp, value);
					return (cmp->right);
				}
				cmp = cmp->right;
			}
		}
	}
	return (NULL);
}
