#include "sort.h"

/**
* cocktail_sort_list - sorts a list using the
* cocktail sort algorithm
*
* @list: The doubly list to be sorted
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *temp_t;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	curr = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (curr->next != NULL)
		{
			if (curr->n > curr->next->n)
			{
				temp_t = curr->next;
				curr->next = temp_t->next;
				if (temp_t->next != NULL)
					temp_t->next->prev = curr;
				temp_t->prev = curr->prev;
				temp_t->next = curr;
				if (curr->prev != NULL)
					curr->prev->next = temp_t;
				else
					*list = temp_t;
				curr->prev = temp_t;
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				temp_t = curr->prev;
				curr->prev = temp_t->prev;
				if (temp_t->prev != NULL)
					temp_t->prev->next = curr;
				temp_t->next = curr->next;
				temp_t->prev = curr;
				if (curr->next != NULL)
					curr->next->prev = temp_t;
				else
					*list = temp_t;
				curr->next = temp_t;
				swapped = 1;
				print_list(*list);
			}
			else
				curr = curr->prev;
		}
	}
}
