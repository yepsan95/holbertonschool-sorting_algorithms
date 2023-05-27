#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 *              order using the Quick sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_recursion(array, 0, size - 1, size);
}

/**
 * quick_recursion - sorts an array of integers in ascending
 *                   order using the Quick sort algorithm
 * @array: array of integers to be sorted
 * @first: index of the first element in the partition
 * @last: index of the last element in the partition
 * @size: size of the array
 *
 * Return: void
 */
void quick_recursion(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first >= last)
		return;

	pivot = partition(array, first, last, size);

	quick_recursion(array, first, pivot - 1, size);
	quick_recursion(array, pivot + 1, last, size);
}

/**
 * partition - performs a Quick sort in a partition of an array of integers
 * @array: array of integers to be sorted
 * @first: index of the first element in the partition
 * @last: index of the last element in the partition
 * @size: total size of the original array
 *
 * Return: void
 */
int partition(int *array, int first, int last, size_t size)
{
	int pivot, i, j;

	pivot = array[last];
	i = first - 1;

	for (j = first; j < last; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_int(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	i++;
	swap_int(&array[i], &array[last]);
	if (i != j)
		print_array(array, size);

	return (i);
}

/**
 * swap_int - swaps to integers from an arrray
 * @a: pointer to first integer
 * @b: pointer to second integer
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
