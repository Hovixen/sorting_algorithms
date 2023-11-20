#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linkedlist
 * @list: doubly linkedles list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;

	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap - swap a node with its previous node
 * @node: node to be swapped
 * @list: pointer to a pointer to the head of the list
 * Return: pointer to the upudated node
 */

listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *temp = node->prev, *current = node;

	temp->next = current->next;
	if (current->next)
		current->next->prev = temp;
	current->next = temp;
	current->prev = temp->prev;
	temp->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
	{
		*list = current;
	}
	return (current);
}
