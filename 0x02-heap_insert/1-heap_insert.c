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
	binary_tree_t *new_node = binary_tree_node(*root, value), *current = *root;

	if (!new_node)
		return (NULL);
	if (!*root)
	{
		/* Insert created node at root */
		*root = new_node;
	}
	else
	{
		/* current->n can be < new_node->n */
		/* OR current->n can be > new_node->n */
		/* OR current->n can be == new_node->n ?!?!?!?! */
		while (current)
		{
			printf("Current->n is: %d\n", current->n);
			printf("New_node->n is: %d\n", new_node->n);
			if (current->n < new_node->n)
			{
				/* Move current to new_node->left */
				new_node->left = current;
				if (!current->parent)
					*root = new_node;
				current->parent = new_node;
			}
			else if (current->n > new_node->n)
			{
				/* Move current to new_node->right */
				new_node->right = current;
				if (!current->parent)
					*root = new_node;
				current->parent = new_node;
			}
			current = current->left;
		}
	}
	return (new_node);
}
