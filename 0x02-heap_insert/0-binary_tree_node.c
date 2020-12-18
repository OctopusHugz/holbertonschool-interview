#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: Integer stored in the node
 * Return: pointer to the created node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t) * 1);

	if (!node)
		return NULL;
	node->n = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	if (parent)
		node->parent = parent;
	return (node);
}
