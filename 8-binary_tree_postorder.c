#include "binary_trees.h"

/**
 * binary_tree_postorder - goes throught a bianry tree
 * using post-order traversal
 * @tree: pointer to the root node if the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
func(tree->n);
}
