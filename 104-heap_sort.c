#include "sort.h"

/**
 * swap_func - Swap two integers
 * @ele1: The first integer to swap.
 * @ele2: The second integer to swap.
 */

void swap_func(int *ele1, int *ele2)
{
	int temp;

	temp = *ele1;
	*ele1 = *ele2;
	*ele2 = temp;
}

/**
 * mx_heap - converts binary tree to head
 * @array: array to be sorted
 * @size: array size
 * @lower: The index of the base row of the tree.
 * @upper: The root node of the binary tree.
 */
void mx_heap(int *array, size_t lower, size_t upper, size_t size)
{
	size_t start, end, large;

	start = 2 * upper + 1;
	end = 2 * upper + 2;
	large = upper;

	if (start < lower && array[start] > array[large])
		large = start;
	if (end < lower && array[end] > array[large])
		large = end;

	if (large != upper)
	{
		swap_func(array + upper, array + large);
		print_array(array, size);
		mx_heap(array, size, lower, large);
	}
}

/**
 * heap_sort - Sort an array of integers using the heap sort algorithm.
 * @array: An array of integers.
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2); i >= 1; i--)
		mx_heap(array, size, size, i);

	for (i = size; i >= 0; i--)
	{
		swap_func(array, array + i);
		print_array(array, size);
		mx_heap(array, size, i, 0);
	}
}
