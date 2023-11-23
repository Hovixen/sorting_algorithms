#include "sort.h"

/**
 * print_merge_step - Print the intermediate steps of the merge sort algorithm.
 * @arr: The array being sorted.
 * @low: The starting index of the current subarray.
 * @mid: The middle index of the current subarray.
 * @high: The ending index of the current subarray.
 */

void print_merge_step(int *arr, int low, int mid, int high)
{
	int left, right;

	left = mid - low + 1;
	right = high - mid;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(&arr[low], left);
	printf("[right]: ");
	print_array(&arr[mid + 1], right);
	printf("[Done]: ");
	print_array(&arr[low], left + right);
}

/**
 * merge_help - Helper function for merging two sorted halves of an array.
 * @arr: The original array.
 * @sorted: The auxiliary array to store the sorted elements.
 * @mid: The middle index of the current subarray.
 * @high: The ending index of the current subarray.
 * @i: Index for the left half of the subarray.
 * @j: Index for the right half of the subarray.
 * @k: Index for the merged subarray.
 */

void merge_help(int *arr, int *sorted, int mid,
		int high, int i, int j, int k)
{
	if (i > mid)
	{
		while (j <= high)
		{
			sorted[k] = arr[j];
			j++, k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			sorted[k] = arr[i];
			i++, k++;
		}
	}
}

/**
 * merge - Merge two sorted halves of an array.
 * @arr: The original array.
 * @low: The starting index of the current subarray.
 * @mid: The middle index of the current subarray.
 * @high: The ending index of the current subarray.
 * @size: The size of the array.
 */

void merge(int *arr, int low, int mid, int high, size_t size)
{
	int i = low, j = mid + 1, k = low;
	int *sorted;
	size_t n;

	sorted  = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	for (n = 0; n <= size; n++)
		sorted[n] = 0;

	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			sorted[k] = arr[i];
			i++;
		}
		else
		{
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	merge_help(arr, sorted, mid, high, i, j, k);
	print_merge_step(arr, low, mid, high);

	/*copy the sorted array into the main array*/
	for (k = low; k <= high; k++)
	{
		arr[k] = sorted[k];
	}
	free(sorted);
}

/**
 * mergeSort - Recursive function to perform the merge sort algorithm.
 * @arr: The array to be sorted.
 * @low: The starting index of the current subarray.
 * @high: The ending index of the current subarray.
 * @size: The size of the array.
 */

void mergeSort(int *arr, int low, int high, size_t size)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		mergeSort(arr, low, mid, size);
		mergeSort(arr, mid + 1, high, size);
		merge(arr, low, mid, high, size);
	}
}

/**
 * merge_sort - Function to initiate the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	mergeSort(array, 0, size - 1, size);
}

