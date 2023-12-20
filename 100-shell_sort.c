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
 * shell_sort - sort an array with shell sort method
 * @array: the array to be sorted
 * @size: array size
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
	{
		gap = 3 * gap + 1;
	}

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			temp = array[j];
			for (; j >= gap && array[j - gap] > temp; j -= gap)
			{
				swap_func(array + j, array + (j - gap));
			}
		}
		print_array(array, size);
	}
}
