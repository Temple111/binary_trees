#include "binary_trees.h"

/**
 * tree_hgt - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_hgt(const heap_t *tree)
{
	size_t height_a = 0;
	size_t height_b = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_a = 1 + tree_hgt(tree->left);

	if (tree->right)
		height_b = 1 + tree_hgt(tree->right);

	if (height_a > height_b)
		return (height_a);
	return (height_b);
}
/**
 * sum_hgt - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t sum_hgt(const binary_tree_t *tree)
{
	size_t height_a = 0;
	size_t height_b = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_a = 1 + sum_hgt(tree->left);

	if (tree->right)
		height_b = 1 + sum_hgt(tree->right);

	return (height_a + height_b);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @nd: will be last note in traverse
 * @hgt: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **nd, size_t hgt)
{
	if (!tree)
		return;

	if (!hgt)
		*nd = tree;
	hgt--;

	_preorder(tree->left, nd, hgt);
	_preorder(tree->right, nd, hgt);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int val;
	heap_t *cmp1, *cmp2;

	if (!root)
		return;

	cmp1 = root;

	while (1)
	{
		if (!cmp1->left)
			break;
		if (!cmp1->right)
			cmp2 = cmp1->left;
		else
		{
			if (cmp1->left->n > cmp1->right->n)
				cmp2 = cmp1->left;
			else
				cmp2 = cmp1->right;
		}
		if (cmp1->n > cmp2->n)
			break;
		val = cmp1->n;
		cmp1->n = cmp2->n;
		cmp2->n = val;
		cmp1 = cmp2;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
	int val;
	heap_t *heap_a, *nd;

	if (!root || !*root)
		return (0);
	heap_a = *root;
	val = heap_a->n;
	if (!heap_a->left && !heap_a->right)
	{
		*root = NULL;
		free(heap_a);
		return (val);
	}

	_preorder(heap_a, &nd, tree_hgt(heap_a));

	heap_a->n = nd->n;
	if (nd->parent->right)
		nd->parent->right = NULL;
	else
		nd->parent->left = NULL;
	free(nd);
	heapify(heap_a);
	*root = heap_a;
	return (val);
}
