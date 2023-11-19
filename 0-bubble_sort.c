#include "sort.h"

/**
 * bubble_sort - sorting function
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	long unsigned int i, j, temp, flag;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				print_array(array, size);
				temp = array[j];
				print_array(array, size);
				array[j] = array[j + 1];
				print_array(array, size);
				array[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
