#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions array using Lomuto scheme
 * @array: Array to partition
 * @low: Start index
 * @high: End index (pivot)
 * @size: Size of the array
 * Return: Index of pivot after partition
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i = low;
	size_t j;
	int pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_rec - Recursively applies Quick sort
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array
 */
void quick_sort_rec(int *array, size_t low, size_t high, size_t size)
{
	size_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		if (p > 0)
			quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition)
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
