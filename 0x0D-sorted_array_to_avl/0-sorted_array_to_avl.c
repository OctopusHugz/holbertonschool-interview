#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to root node of AVL tree created, or NULL on failure
 **/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = malloc(sizeof(avl_t) * 1);

	if (!root)
		return (NULL);
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
	if (size % 2 == 0)
		root->n = array[size / 2 - 1];
	else
		root->n = array[size / 2];
	return (root);
}
