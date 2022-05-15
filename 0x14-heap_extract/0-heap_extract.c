#include "binary_trees.h"

/**
 * heap_extract - Function that extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: The value stored in the root node.
 **/
int heap_extract(heap_t **root)
{
	int value, value_aux;
	heap_t *aux;

	if (!root || !*root)
		return (0);
	aux = *root;
	value = aux->n;
	if (!aux->left && !aux->right && !aux->parent)
	{
		free(aux);
		return (value);
	}
	while (aux->left || aux->right)
	{
		if (aux->left && aux->right)
		{
			if (!aux->right || aux->left->n > aux->right->n)
			{
				value_aux = aux->n;
				aux->n = aux->left->n;
				aux->left->n = value_aux;
				aux = aux->left;
			}
			else if (aux->left->n < aux->right->n)
			{
				value_aux = aux->n;
				aux->n = aux->right->n;
				aux->right->n = value_aux;
				aux = aux->right;

			}
		}
	}
	return (value);
}
