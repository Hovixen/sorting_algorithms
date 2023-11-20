#include "sort.h"

/**
 * swap_elements - function swaps two elements in an arrray
 * @a: first element
 * @b: second element
 * Return: returns void
 */

void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * get_pivot - function gets the pivot of an array
 *
 * Description: this implements the Lomuto partition for choosing the
 * last element of the array as pivot
 *
 * @array: pointer to the given array
 * @low: index of first element
 * @high: index of last element
 * Return: returns the index of the pivot element
 */

int get_pivot(int *array, int low, int high)
{
	int pivot_elem, n, m;

	pivot_elem = array[high]; /* pivot as last element */
	n = low - 1;

	for (m = low; m <= high - 1; m++)
	{
		if (array[m] <= pivot_elem)
		{
			n++;
			swap_elements(&array[n], &array[m]);
			print_array(array, high - low + 1);
		}
	}

	swap_elements(&array[n + 1], &array[high]);
	print_array(array, high - low + 1);
	return (n + 1);
}

/**
 * sort_array - function implements Lomuto partition recursively
 * @array: pointer to the given array
 * @low: index of the first element
 * @high: index of the last element
 * Return: returns void
 */

void sort_array(int *array, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = get_pivot(array, low, high);
		sort_array(array, low, pivot_idx -1);
		sort_array(array, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - function initializes the quick_sort algorithm
 * @size: size of the given array
 * Return: returns void
 */

void quick_sort(int *array, size_t size)
{
	sort_array(array, 0, size - 1);
}
