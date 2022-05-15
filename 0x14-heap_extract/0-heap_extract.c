#include "binary_trees.h"

/**
 * heap_size - Gets the size of heap
 * @heap: Pointer to root
 * Return: Size of heap
 */
int heap_size(heap_t *heap)
{
	return (heap ? 1 + heap_size(heap->left) + heap_size(heap->right) : 0);
}

/**
 * heap_restore - Restores heap property from root.
 * @heap: Pointer to heap struct.
 */
void heapify_down(heap_t *heap)
{
	heap_t *node = heap, *child;
	int temp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = node->left->n > node->right->n ?
				node->left : node->right;
		if (node->n > child->n)
			break;
		temp = node->n;
		node->n = child->n;
		child->n = temp;
		node = child;
	}
}

/**
 * heap_extract - Function that extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: The value stored in the root node.
 **/
int heap_extract(heap_t **heap)
{
	int n, size, bit;
	heap_t *node, *root;

	if (!heap || !*heap)
		return (0);
	root = *heap;
	n = root->n;
	size = heap_size(root);
	if (size == 1)
	{
		free(root);
		*heap = NULL;
		return (n);
	}
	for (bit = 1; bit <= size; bit <<= 1)
		;
	bit >>= 2;
	for (node = root; bit > 0; bit >>= 1)
		node = size & bit ? node->right : node->left;
	root->n = node->n;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	free(node);
	heapify_down(root);
	*heap = root;
	return (n);
}
