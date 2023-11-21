#include "sort.h"

/**
 * shell_swap - swap element function
 * @array: array of elements
 * @item1: item1
 * @item2: item2
 *
 * Return: void
 */

void shell_swap(int *array, int item1, int item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
 * shell_sort - sorts an array of integers in ascending
 * order using the shell sort algorithm with knuth
 * sequence.
 * @array: array of elements
 * @size: size of elements
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t i = 0, j, gap = 1;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap *= 3 + 1;

	while (gap >= 1)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j; i >= gap &&
			(array[i] < array[i - gap]); i -= gap)
				shell_swap(array, i, i - gap);
		}
		print_array(array, size);
		gap /= 3;
	}
}
