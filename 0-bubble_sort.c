#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int tmp, check;
	size_t i;

	check = 1;
	while (check == 1)
	{

		check = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				check = 1;
			}
		}
	}
}
