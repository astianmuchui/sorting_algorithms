#include "sort.h"

/**
 * shell_sort - function that sorts an array
 * of integers in ascending order using the
 * Shell sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		_ssort(array, size, n);
}
/**
 * _ssort - auxiliar function for
 * shell_sort function
 * @a: input arrray
 * @size: size of the array
 * @n: intervale
 * Return: no return
 */
void _ssort(int *a, int size, int n)
{
	int tmp, s, b;

	for (s = 0; (s + n) < size; s++)
	{
		for (b = s + n; (b - n) >= 0; b = b - n)
		{
			if (a[b] < a[b - n])
			{
				tmp = a[b];
				a[b] = a[b - n];
				a[b - n] = tmp;
			}
		}
	}
	print_array(a, size);

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
