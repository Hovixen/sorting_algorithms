#include "sort.h"

/**
 * swap_nodes - function swaps the node of in doubly linked list
 * @list: pointer to the pointer to list
 * @n1: pointer to the first node
 * @n2: pointer to the second node
 * Return: returns void
 */

void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	else
		*list = n2;
	if (n2->next)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->prev = n1->prev;

	n1->prev = n2;
	n2->next = n1;
}

/**
 * insertion_sort_list - function sorts list using insertion sort algorithm
 * @list: pointer of list pointer
 * Return: returns void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *s_list;/* sorted part of list */
	listint_t *u_list; /*unsorted part of list */

	if (*list == NULL || (*list)->next == NULL || *list == NULL)
		return;
	u_list = (*list)->next;
	while (u_list)
	{
		s_list = u_list->prev;
		while (s_list && s_list->n > u_list->n)
		{
			swap_nodes(list, s_list, u_list);
			print_list(*list);
			s_list = u_list->prev;
		}
		u_list = u_list->next;
	}
}
