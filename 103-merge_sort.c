#include "sort.h"

/**
 * merge_subarr - merge sub arrays to single sorted array
 * @subarr: subarray of integer
 * @new_array: space to store new array
 * @low_b: The front index of the array.
 * @mid: The middle index of the array.
 * @up_b: The back index of the array.
 */
void merge_function(int *subarr, int *new_array, size_t low_b, size_t mid,
		size_t up_b)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + low_b, mid - low_b);

	printf("[right]: ");
	print_array(subarr + mid, up_b - mid);

	for (i = low_b, j = mid; i < mid && j < up_b; k++)
	{
		new_array[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	}

	while (i < mid)
	{
		new_array[k++] = subarr[i++];
	}

	while (j < up_b)
	{
		new_array[k++] = subarr[j++];
	}

	for (i = low_b, k = 0; i < up_b; i++)
	{
		subarr[i] = new_array[k++];
	}

	printf("[Done]: ");
	print_array(subarr + low_b, up_b - low_b);
}

/**
 * merge_sort_function - divide array into subarrays
 * @subarr: A subarray of an array of integers to sort.
 * @new_array: space to store newly formed array
 * @up_b: upper boundary
 * @low_b: lower boundary
 */
void merge_sort_function(int *subarr, int *new_array, size_t low_b,
	size_t up_b)
{
	size_t mid;

	if (low_b - up_b > 1)
	{
		mid = low_b + (up_b - low_b) / 2;
		merge_sort_function(subarr, new_array, low_b, mid);
		merge_sort_function(subarr, new_array, mid + 1, up_b);
		merge_function(subarr, new_array, low_b, mid, up_b);
	}
}

/**
 * merge_sort - Sort an array using the merge sort
 * @array: An array of integers.
 * @size: array size
 */
void merge_sort(int *array, size_t size)
{
	int *new_array;

	if (array == NULL || size < 2)
		return;

	new_array = malloc(sizeof(int) * size);

	if (new_array == NULL)
		return;

	merge_sort_function(array, new_array, 0, size);
	free(new_array);
}
