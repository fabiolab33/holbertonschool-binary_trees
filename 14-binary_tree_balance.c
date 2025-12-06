#include "binary_trees.h"

/**
 * height - measure the height of a binary tree
 * @tree: pointer to the node to measure
 *
 * Return: height or 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
size_t left_h = 0, right_h = 0;

if (tree == NULL)
return (0);

left_h = tree->left ? 1 + height(tree->left) : 1;
right_h = tree->right ? 1 + height(tree->right) : 1;

return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_balance - meaasure the balance factor of a binary tree
 * @tree: pointer to the root node
 *
 * Return: balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (height(tree->left) - height(tree->right));
}
