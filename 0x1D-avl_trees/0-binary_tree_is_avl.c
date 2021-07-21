#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 **/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int root_bf, left_st_bf, right_st_bf;

	if (!tree)
		return (0);
	root_bf = binary_tree_balance(tree);
	left_st_bf = binary_tree_balance(tree->left);
	right_st_bf = binary_tree_balance(tree->right);
	if (root_bf < -1 || root_bf > 1 || left_st_bf > 1 || right_st_bf < -1)
		return (0);
	else if (!is_BST(tree, tree->n))
		return (0);
	return (1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of tree, or 0 if tree is NULL
 **/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (tree->left)
		left = 1 + binary_tree_height(tree->left);
	else
		left = 0;
	if (tree->right)
		right = 1 + binary_tree_height(tree->right);
	else
		right = 0;
	return (MAX(left, right));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the tree, or 0 if tree is NULL
 **/

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_bal = 0, right_bal = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left_bal = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_bal = 1 + binary_tree_height(tree->right);
	return (left_bal - right_bal);
}

/**
 * is_BST - determines if tree is a BST
 * @tree: pointer to the root node of the tree to check for valid BST
 * @val: value of the root node of the tree
 * Return: 1 if valid BST, 0 if not
 **/
int is_BST(const binary_tree_t *tree, int val)
{
	if (!tree)
		return (0);
	if (tree->left && (tree->left->n >= val || !is_BST(tree->left, val)))
	{
		if (tree->left->n >= val && tree->left->n <= tree->n)
			return (1);
		return (0);
	}
	if (tree->right && (tree->right->n <= val || !is_BST(tree->right, val)))
	{
		if (tree->right->n <= val && tree->right->n >= tree->n)
			return (1);
		return (0);
	}
	return (1);
}
