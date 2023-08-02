#include "binary_trees.h"

bst_t *inord_successor(bst_t *base);
bst_t *bst_Delete(bst_t *base, bst_t *nd);
bst_t *bst_remove_recursive(bst_t *base, bst_t *nd, int val);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inord_successor - Returns the minimum value of a binary search tree.
 * @base: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inord_successor(bst_t *base)
{
	while (base->left != NULL)
		base = base->left;
	return (base);
}

/**
 * bst_Delete - Deletes a node from a binary search tree.
 * @base: A pointer to the root node of the BST.
 * @nd: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_Delete(bst_t *base, bst_t *nd)
{
	bst_t *parent = nd->parent, *successor = NULL;

	/* No children or right-child only */
	if (nd->left == NULL)
	{
		if (parent != NULL && parent->left == nd)
			parent->left = nd->right;
		else if (parent != NULL)
			parent->right = nd->right;
		if (nd->right != NULL)
			nd->right->parent = parent;
		free(nd);
		return (parent == NULL ? nd->right : base);
	}

	/* Left-child only */
	if (nd->right == NULL)
	{
		if (parent != NULL && parent->left == nd)
			parent->left = nd->left;
		else if (parent != NULL)
			parent->right = nd->left;
		if (nd->left != NULL)
			nd->left->parent = parent;
		free(nd);
		return (parent == NULL ? nd->left : base);
	}

	/* Two children */
	successor = inord_successor(nd->right);
	nd->n = successor->n;

	return (bst_Delete(base, successor));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *base, bst_t *nd, int val)
{
	if (nd != NULL)
	{
		if (nd->n == val)
			return (bst_Delete(base, nd));
		if (nd->n > val)
			return (bst_remove_recursive(base, nd->left, val));
		return (bst_remove_recursive(base, nd->right, val));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
