#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *nw, *flp;
	int sz, leaves_0, sub_0, bit, level, cmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	sz = binary_tree_size(tree);
	leaves_0 = sz;
	for (level = 0, sub_0 = 1; leaves_0 >= sub_0; sub_0 *= 2, level++)
		leaves_0 -= sub_0;
	/* subtract all nodes except for bottom-most level */

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves_0 & bit ? tree->right : tree->left;
	/*
	 * Traverse tree to first empty slot based on the binary
	 * representation of the number of leaves.
	 * Example -
	 * If there are 12 nodes in a complete tree, there are 5 leaves on
	 * the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The first empty node is 101 == RLR, *root->right->left->right
	 */

	nw = binary_tree_node(tree, value);
	leaves_0 & 1 ? (tree->right = nw) : (tree->left = nw);

	flp = nw;
	for (; flp->parent && (flp->n > flp->parent->n); flp = flp->parent)
	{
		cmp = flp->n;
		flp->n = flp->parent->n;
		flp->parent->n = cmp;
		nw = nw->parent;
	}
	/* Flip values with parent until parent value exceeds new value */

	return (nw);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
