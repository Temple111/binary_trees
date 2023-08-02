#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @node: pointer to the node to measure the depth of
 *
 * Return: depth of a node in a binary tree. If node is NULL, return 0
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth_count = 0;

	if (node == NULL)
		return (depth_count);
	while (node->parent != NULL)
	{
		depth_count++;
		node = node->parent;
	}
	return (depth_count);
}
