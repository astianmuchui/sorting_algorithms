#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order
* using the Shell sort algorithm, using the Knuth sequence
*
* @array: The array to be printed
* @size: Number of elements in @param @array
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
