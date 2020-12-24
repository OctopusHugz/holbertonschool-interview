#include "binary_trees.h"

/**
 * head_insert - Creates a binary tree node
 *
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	/* size_t node_count; */
	binary_tree_t *new_node = binary_tree_node(*root, value) /* *current = *root */;

	if (!new_node)
		return (NULL);
	if (!*root)
		*root = new_node;
	/* else
	{
		while (current)
		{
			if (current->n < new_node->n)
			{
				new_node->left = current;
				if (!current->parent)
					*root = new_node;
				current->parent = new_node;
			}
			else if (current->n > new_node->n)
			{
				new_node->right = current;
				if (!current->parent)
					*root = new_node;
				current->parent = new_node;
			}
			current = current->left;
		}
	} */
	return (new_node);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count
 * the number of nodes with at least 1 child
 * Return: number of nodes in tree with at least 1 child, or 0 if tree is NULL
 **/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		count += 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
	return (count);
}
