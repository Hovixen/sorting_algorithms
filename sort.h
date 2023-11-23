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


/*----helper swaps functions-----*/
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2);
void swap_elements(int *array, ssize_t a, ssize_t b);
int pertition(int *array, ssize_t first, ssize_t last, size_t size);
void quickSort(int *array, ssize_t first, ssize_t last, size_t size);
void shell_swap(int *array, int item1, int item2);
int get_max(int *arr, size_t size);
void initialize_zero(int *arr, int n);


#endif
