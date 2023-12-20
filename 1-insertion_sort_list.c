#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list using insertion sort.
 *
 * @list: A pointer to the head node of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_n = NULL, *next_n = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;

	current_n = *list;
	while (current_n != NULL)
	{
		next_n = current_n->next;
		insertion_sort_element(list, current_n);
		current_n = next_n;
	}
}

/**
 * insertion_sort_element - Insert an element into its correct position.
 *
 * @list: A pointer to the head node of the list.
 * @element: The element to be inserted.
 */

void insertion_sort_element(listint_t **list, listint_t *element)
{
	listint_t *tmp = NULL;

	tmp = element;
	while (tmp->prev != NULL && tmp->prev->n > tmp->n)
	{
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
		tmp->next = tmp->prev;
		tmp->prev = tmp->prev->prev;
		tmp->next->prev = tmp;

		if (tmp->prev == NULL)
			*list = tmp;
		else
			tmp->prev->next = tmp;
		print_list(*list);
	}
}






