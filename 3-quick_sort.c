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
	int pivot, tmp;
	size_t i, j;

	if (array == NULL || size <= 1)
		return;

	pivot = array[size - 1];
	i = -1;
	for (j = i + 1; j <= size - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[size - 1];
	array[size - 1] = tmp;
	pivot = array[i + 1];
	print_array(array, size);

	quick_sort(array, i + 1);
	quick_sort(array + i + 1, size - 1 - i);
}
