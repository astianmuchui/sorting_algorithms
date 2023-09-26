#include "sort.h"

/**
* insertion_sort_list - sorts a list using the
* insertion sort algorithm
*
* @list: The doubly list to be sorted
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp_t;

	if (list == NULL || *list == NULL)
		return;

	curr = *list;
	while (curr != NULL)
	{
		temp_t = curr;
		while (temp_t->prev != NULL && temp_t->n < temp_t->prev->n)
		{
			temp_t->prev->next = temp_t->next;
			if (temp_t->next != NULL)
				temp_t->next->prev = temp_t->prev;
			temp_t->next = temp_t->prev;
			temp_t->prev = temp_t->prev->prev;
			temp_t->next->prev = temp_t;
			if (temp_t->prev == NULL)
				*list = temp_t;
			else
				temp_t->prev->next = temp_t;
			print_list(*list);
		}
		curr = curr->next;
	}
}
