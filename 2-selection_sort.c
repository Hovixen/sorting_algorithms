#include "sort.h"

/**
 * selection_sort - Sort array in ascending order
 * @array: array of elements
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, temp, flag = 0;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				flag = 1;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;

		if (flag != 0)
			print_array(array, size);
	}
}
