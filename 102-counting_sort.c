#include "sort.h"

/**
 * get_max - get maximum number in the array
 * @arr: array of elements
 * @size: size of the array
 *
 * Return: maximum
 */

int get_max(int *arr, size_t size)
{
	int max = arr[0];
	size_t i;

	if (arr == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * initialize_zero  - initialize the array to zero
 * @arr: array of elements
 * @n: size of the array
 *
 * Return: void
 */

void initialize_zero(int *arr, int n)
{
	int i;

	for (i = 0; i <= n; i++)
		arr[i] = 0;
}

/**
 * counting_sort - counting sort algorithm
 * @array: array
 * @size: size
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count_arr, *sort_arr, k, j, n;

	if (array ==  NULL || size < 2)
		return;

	k = get_max(array, size);
	count_arr = malloc(sizeof(int) * (k + 1));

	if (count_arr == NULL)
		return;
	initialize_zero(count_arr, k);

	for (i = 0; i < size; i++)
		count_arr[array[i]]++;

	/*update count_arr to store position of each element*/
	for (j = 1; j <= k; j++)
		count_arr[j] += count_arr[j - 1];
	print_array(count_arr, k + 1);

	sort_arr = malloc(sizeof(int) * size);
	if (sort_arr == NULL)
	{
		free(count_arr);
		return;
	}

	/*populate the sorted array*/
	for (n = size - 1; n >= 0; n--)
		sort_arr[--count_arr[array[n]]] = array[n];
	for (i = 0; i < size; i++)
		array[i] = sort_arr[i];

	free(count_arr);
	free(sort_arr);

}
