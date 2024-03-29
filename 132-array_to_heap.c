#include "binary_trees.h"

/**
 * array_to_heap - A function that builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
unsigned int x = 0;
heap_t *found = NULL;

while (x < size)
{
heap_insert(&found, array[x]);
x++;
}

return (found);
}

