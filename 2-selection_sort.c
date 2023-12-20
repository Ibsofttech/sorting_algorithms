#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order with selection sort
 * @array: an array to be sorted
 * @size: the size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t pass, elements, minimum;
	int temp;

	for (pass = 0; pass < size - 1; pass++)
	{
		minimum = pass;
		for (elements = pass + 1; elements < size; elements++)
		{
			if (array[elements] < array[minimum])
				minimum = elements;
		}
		if (minimum != pass)
		{
			temp = array[pass];
			array[pass] = array[minimum];
			array[minimum] = temp;
			print_array(array, size);
		}
	}
}
