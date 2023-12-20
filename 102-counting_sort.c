#include "sort.h"

#include "sort.h"

/**
 * max_element - find the maximum element in an array of integers.
 * @array: array of integers.
 * @size: array size;
 *
 * Return: The maximum integer in the array.
 */
int max_element(int *array, int size)
{
	int max = 0, i;

	if (size <= 0)
	{
		return (-1);
	}
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort
 * @array: An array of integers.
 * @size: arrsy size
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;
	max = max_element(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] =	count[i] + count[i - 1];
	print_array(count, max + 1);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--)
		sorted[--count[array[i]]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}
