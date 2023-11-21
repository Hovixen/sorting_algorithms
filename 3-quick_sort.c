#include "sort.h"

/**
 * swap_elements - function swaps two elements in an arrray
 * @array: array
 * @a: first elemen
 * @b: second element
 * Return: returns void
 */

void swap_elements(int *array, ssize_t a, ssize_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * pertition - pertition function
 * @array: array of elements
 * @first: first element
 * @last: last element
 * @size: size of the array
 *
 * Return: the current index of the pivot
 */

int pertition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t curr = first, i;

	for (i = first; i < last; i++)
	{
		if (array[i] < pivot)
		{
			if (array[curr] != array[i])
			{
				swap_elements(array, curr, i);
				print_array(array, size);
			}
			curr++;
		}
	}
/*	if (array[curr] != array[last])*/
/*	{*/
		swap_elements(array, curr, last);
		print_array(array, size);
/*	}*/
	return (curr);
}

/**
 * quickSort - sorts an array of integers using the
 * quick_sort algorithm
 * @array: array of elements
 * @first: first element
 * @last: last element
 * @size: size of the array
 */

void quickSort(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = pertition(array, first, last, size);
		quickSort(array, first, position - 1, size);
		quickSort(array, position + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of integers
 * @array: array of elements
 * @size: soze of the array
 */

void quick_sort(int *array, size_t size)
{
/*	if (array == NULL || size < 2)*/
/*		return;*/
	quickSort(array, 0, size - 1, size);
}

