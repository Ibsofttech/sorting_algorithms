#include "sort.h"

/**
 * bubble_sort - sorts the array in ascending order with bubble sort
 * @array: the array to be sorted
 * @size: number of element in the array
 *
 * Return: NULL
 */

void bubble_sort(int *array, size_t size)
{
	size_t pass, array_sort, array_flag, temp;

	if (array)
	{
		for (pass = 0; pass < size - 1; pass++)
		{
			array_flag = 0;
			for (array_sort = 0; array_sort < size - 1 - pass; array_sort++)
			{
				if (array[array_sort] > array[array_sort + 1])
				{
					temp = array[array_sort];
					array[array_sort] = array[array_sort + 1];
					array[array_sort + 1] = temp;
					print_array(array, size);
					array_flag = 1;
				}
			}
			if (array_flag == 0)
			{
				break;
			}
		}
	}
}
