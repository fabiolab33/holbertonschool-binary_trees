#include "binary_trees.h"

/**
 * height - measure the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
size_t left_h, right_h;

if (tree == NULL)
return (0);

left_h = tree->left ? 1 + height(tree->left) : 0;
right_h = tree->right ? 1 + height(tree->right) : 0;

return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t left_h, right_h;

if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (1);

if (!tree->left || !tree->right)
return (0);

left_h = height(tree->left);
right_h = height(tree->right);

if (left_h != right_h)
return (0);

return (binary_tree_is_perfect(tree->left) &&
binary_tree_is_perfect(tree->right));
}
