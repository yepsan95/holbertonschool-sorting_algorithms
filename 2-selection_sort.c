#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int min;
	size_t i, j, min_index;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_index = j;
			}
		}
		if (min != array[i])
		{
			array[min_index] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
