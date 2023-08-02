#include "binary_trees.h"

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
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: the generated array
 *         NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int a, *b = NULL;

	if (!heap || !size)
		return (NULL);

	*size = sum_hgt(heap) + 1;

	b = malloc(sizeof(int) * (*size));

	if (!b)
		return (NULL);

	for (a = 0; heap; a++)
		b[a] = heap_extract(&heap);

	return (b);
}
