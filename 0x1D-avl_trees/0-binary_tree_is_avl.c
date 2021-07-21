#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 **/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int root_balance_factor = binary_tree_balance(tree);
	int left_st_bf = binary_tree_balance(tree->left);
	int right_st_bf = binary_tree_balance(tree->right);

	if (!tree || root_balance_factor < -1 || root_balance_factor > 1)
		return (0);
	else if (left_st_bf > 1 || right_st_bf < -1)
		return (0);
	return (1);
}
