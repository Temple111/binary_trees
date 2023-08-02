#include "binary_trees.h"

/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int b_val;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	b_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (b_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - get the next successor i mean the min node in the right subtree
 * @nd: tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *nd)
{
	int lft = 0;

	if (nd == NULL)
	{
		return (0);
	}
	else
	{
		lft = successor(nd->left);
		if (lft == 0)
		{
			return (nd->n);
		}
		return (lft);
	}

}
/**
 *remove_type - function that removes a node depending of its children
 *@base: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *base)
{
	int nw_val = 0;

	if (!base->left && !base->right)
	{
		if (base->parent->right == base)
			base->parent->right = NULL;
		else
			base->parent->left = NULL;
		free(base);
		return (0);
	}
	else if ((!base->left && base->right) || (!base->right && base->left))
	{
		if (!base->left)
		{
			if (base->parent->right == base)
				base->parent->right = base->right;
			else
				base->parent->left = base->right;
			base->right->parent = base->parent;
		}
		if (!base->right)
		{
			if (base->parent->right == base)
				base->parent->right = base->left;
			else
				base->parent->left = base->left;
			base->left->parent =base->parent;
		}
		free(base);
		return (0);
	}
	else
	{
		nw_val = successor(base->right);
		base->n = nw_val;
		return (nw_val);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @base: root of the tree
 * @val: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *base, int val)
{
	int type = 0;

	if (base == NULL)
		return (NULL);
	if (val < base->n)
		bst_remove(base->left, val);
	else if (val > base->n)
		bst_remove(base->right, val);
	else if (val == base->n)
	{
		type = remove_type(base);
		if (type != 0)
			bst_remove(base->right, type);
	}
	else
		return (NULL);
	return (base);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_1 = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_1 == NULL)
		return (NULL);
	bal(&root_1);
	return (root_1);
}
