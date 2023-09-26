#include "sort.h"

/**
* lomuto_partition - partitions an array of integers
* in ascending order using the Lomuto partition scheme
*
* @array: The array to be printed
* @low: Number of elements in @param @array
* @high: Number of elements in @param @array
* @size: Number of elements in @param @array
*
*
* Return: (void)
*/

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;

			if (i != j)
				print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	if (i + 1 != j)
		print_array(array, size);

	return (i + 1);
}

/**
* exec_quicksort - sorts an array of integers in ascending order
* using the Quick sort algorithm
*
*
* @array: The array to be sorted
* @low: The lowest index of the partition to be sorted
* @high: The highest index of the partition to be sorted
* @size: Number of elements in @param @array
*
*
* Return: (void)
*/

void exec_quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		exec_quicksort(array, low, pivot - 1, size);
		exec_quicksort(array, pivot + 1, high, size);
	}
}



/**
* quick_sort - sorts an array of integers in ascending order
* using the Quick sort algorithm
*
* Partition scheme: Lomuto
*
* Print the arr after each swap
*
* @array: The array to be printed
* @size: Number of elements in @param @array
*
*
* Return: (void)
*/



void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	exec_quicksort(array, 0, size - 1, size);
}
