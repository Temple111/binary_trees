#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 *
 * @nd: pointer node
 * @arr: input array of integers
 * @sz: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **nd, int *arr, size_t sz, int mode)
{
	size_t mid;

	if (sz == 0)
		return;

	mid = (sz / 2);
	mid = (sz % 2 == 0) ? mid - 1 : mid;

	if (mode == 1)
	{
		(*nd)->left = binary_tree_node(*nd, arr[mid]);
		create_tree(&((*nd)->left), arr, mid, 1);
		create_tree(&((*nd)->left), arr + mid + 1, (sz - 1 - mid), 2);
	}
	else
	{
		(*nd)->right = binary_tree_node(*nd, arr[mid]);
		create_tree(&((*nd)->right), arr, mid, 1);
		create_tree(&((*nd)->right), arr + mid + 1, (sz - 1 - mid), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *base;
	size_t mid;

	base = NULL;

	if (size == 0)
		return (NULL);

	mid = (size / 2);

	mid = (size % 2 == 0) ? mid - 1 : mid;

	base = binary_tree_node(base, array[mid]);

	create_tree(&base, array, mid, 1);
	create_tree(&base, array + mid + 1, (size - 1 - mid), 2);

	return (base);
}
