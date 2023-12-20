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
 * sort_func - function that sort array
 * @array: the array to be sorted
 * @up_b: upper boundary
 * @low_b: lower boundary
 * @size: array size
 */

void sort_func(int *array, int low_b, int up_b, int size)
{
	int locatiion;

	if (up_b - low_b > 0)
	{
		locatiion = partition_func(array, low_b, up_b, size);
		sort_func(array, low_b, locatiion - 1, size);
		sort_func(array, locatiion + 1, up_b, size);
	}
}


/**
 * partition_func - function that partition array
 * @array: the array to be partitioned
 * @up_b: upper boundary
 * @low_b: lower boundary
 * @size: array size
 * Return: the support index
 */

int partition_func(int *array, int low_b, int up_b, int size)
{
	int *base, i, j;

	base = array + up_b;
	for (i = j = low_b; j < up_b ; j++)
	{
		if (array[j] < *base)
		{
			if (i < j)
			{
				swap_func(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *base)
	{
		swap_func(array + i, base);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort - sort an array with quick sort method
 * @array: the array to be sorted
 * @size: array size
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_func(array, 0, size - 1, size);
}
