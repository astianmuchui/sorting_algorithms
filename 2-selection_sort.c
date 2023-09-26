#include "sort.h"

/**
* selection_sort - Sorts an array of integers
* implementing the Selection sort algorithm
*
* @array: The array to be printed
* @size: Number of elements in @param @array
* Return: (void)
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp_t;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			temp_t = array[i];
			array[i] = array[min];
			array[min] = temp_t;
			print_array(array, size);
		}
	}
}
