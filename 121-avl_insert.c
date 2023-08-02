#include "binary_trees.h"

size_t hgt(const binary_tree_t *tree);
int bal_fact(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **nw, int val);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * hgt - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t hgt(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t a= 0, b = 0;

		a = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		b = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((a > b) ? a : b);
	}
	return (0);
}

/**
 * bal_fact - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int bal_fact(const binary_tree_t *tree)
{
	return (tree != NULL ? hgt(tree->left) - hgt(tree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @nw: A double pointer to store the new node.
 * @val: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **nw, int val)
{
	int b_factor;

	if (*tree == NULL)
		return (*nw = binary_tree_node(parent, val));

	if ((*tree)->n > val)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, nw, val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, nw, val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	b_factor = bal_fact(*tree);
	if (b_factor > 1 && (*tree)->left->n > val)
		*tree = binary_tree_rotate_right(*tree);
	else if (b_factor < -1 && (*tree)->right->n < val)
		*tree = binary_tree_rotate_left(*tree);
	else if (b_factor > 1 && (*tree)->left->n < val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_factor < -1 && (*tree)->right->n > val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *nw = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &nw, value);
	return (nw);
}
