#include "sort.h"

/**
* bubble_sort - Sorts an array of integers
* implementing the Bubble sort algorithm
*
* @array: The array to be printed
* @size: Number of elements in @param @array
* Return: (void)
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp_t;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp_t = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp_t;
				print_array(array, size);
			}
		}
	}
}
