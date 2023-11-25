#include "sort.h"

/**
 * heapSwap - Swaps two elements in an array.
 * @arr: The array containing the elements.
 * @item1: Index of the first element to swap.
 * @item2: Index of the second element to swap.
 */

void heapSwap(int *arr, int item1, int item2)
{
	int temp;

	temp = arr[item1];
	arr[item1] = arr[item2];
	arr[item2] = temp;
}

/**
 * max_heapify - Maintains the max heap property.
 * @arr: The array representing the heap.
 * @size: The total number of elements in the array.
 * @idx: Index of the current node to heapify.
 * @n: The size of the heap to consider.
 */

void max_heapify(int *arr, size_t size, int idx, size_t n)
{
	int largest, right, left;

	largest = idx;
	left = (2 * idx + 1);
	right = (2 * idx + 2);

	while (left < (int)n && arr[left] > arr[largest])
		largest = left;
	while (right < (int)n && arr[right] > arr[largest])
		largest = right;

	if (largest != idx)
	{
		heapSwap(arr, largest, idx);
		print_array(arr, size);
		max_heapify(arr, size, largest, n);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending
 * order using Heap Sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; i--)
	{
		max_heapify(array, size, i, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		heapSwap(array, 0, i);
		print_array(array, size);
		max_heapify(array, size, 0, i);
	}
}

