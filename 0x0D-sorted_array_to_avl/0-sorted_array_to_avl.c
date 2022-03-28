#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

/**
 * sorted_array_to_avl_aux - aux
 * @array: pointer to the first element of the array to be converted
 * @min: lower limit
 * @max: upper limit
 * Return: pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl_aux(int *array, int min, int max)
{
	int half;
	avl_t *tree;

	if (min > max)
		return (NULL);

	half = (max + min) / 2;

	tree = binary_tree_node(NULL, array[half]);
	if (!tree)
		return (NULL);

	tree->left = sorted_array_to_avl_aux(array, min, half - 1);

	tree->right = sorted_array_to_avl_aux(array, half + 1, max);

	if (tree->left)
		tree->left->parent = tree;

	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);

	return (sorted_array_to_avl_aux(array, 0, size - 1));
}
