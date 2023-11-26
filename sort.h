#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*---custom prints---*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
listint_t *create_listint(const int *array, size_t size);

/*----sorting functions----*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void cocktail_sort_list(listint_t **list)

/*----helper swaps functions-----*/
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2);
void swap_elements(int *array, ssize_t a, ssize_t b);
int pertition(int *array, ssize_t first, ssize_t last, size_t size);
void quickSort(int *array, ssize_t first, ssize_t last, size_t size);
void shell_swap(int *array, int item1, int item2);
int get_max(int *arr, size_t size);
void initialize_zero(int *arr, int n);
void mergeSort(int *arr, int *temp, int start, int end);
void merge(int *arr, int *temp, int start, int mid, int end);
void *_calloc(unsigned int num, unsigned int size);
void heapSwap(int *arr, int item1, int item2);
void max_heapify(int *arr, size_t size, int idx, size_t n);
int getMax(int *arr, int n);
void countSort(int *arr, size_t n, int exp, int *output);
void swap(int arr[], int item1, int item2, int order);
void merge_bi(int arr[], int low, int nelemnt, int order);
void bitonicsort(int arr[], int low, int nelemnt, int order, int size);
void swap_qs(int *array, ssize_t item1, ssize_t item2);
int hoare_partition(int *array, int first, int last, int size);
void qs(int *array, ssize_t first, ssize_t last, int size);
listint_t *swap_node(listint_t *node, listint_t **list);

#endif
