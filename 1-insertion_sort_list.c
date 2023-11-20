#include "sort.h"

/**
 * insertion_sort_list - function sorts list using insertion sort algorithm
 * @list: pointer of list pointer
 * Return: returns void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *s_list = NULL; /*sorted part of list */
	listint_t *u_list; /*unsorted part of list */
	listint_t *curr, *tmp;

	if (*list == NULL || (*list)->next == NULL)
		return;
	u_list = *list;
	while (u_list)
	{
		curr = u_list;
		u_list = u_list->next;
		if (!s_list || s_list->n >= curr->n)
		{
			curr->next = s_list;
			curr->prev = NULL;
			if (s_list)
				s_list->prev = curr;
			s_list = curr;
		}
		else
		{
			tmp = s_list;
			while (tmp->next && tmp->next->n < curr->n)
				tmp = tmp->next;
			curr->next = tmp->next;
			curr->prev = tmp;
			if (tmp->next)
				tmp->next->prev = curr;
			tmp->next = curr;
		}
		print_list(s_list);
	}
	*list = s_list;
}
