#include "sort.h"
void swap_list(listint_t *a, listint_t *b);

/**
 *cocktail_sort_list - func that sorts doubly linked list of ints in ascending
 *@list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;

	if (*list == NULL || list == NULL)
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				/**
				 * temp = current->n;
				 * current->n = current->next->n;
				 * current->next->n = temp;
				 */
				swap_node(list, current, current->next);
				swapped = 1;
			}
			print_list(*list);
			current = current->next;
		}

		if (!swapped)
			break;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
                               /**
				* temp = current->n;
                                * current->n = current->prev->n;
                                * current->prev->n = temp;
				*/
				swap_node(list, current->prev, current);
				swapped = 1;
			}
			print_list(*list);
			current = current->prev;
		}
	}while (swapped);
	free(*list);
}


void swap_node(listint_t **list, listint_t *a, listint_t *b)
{
        if (a->prev != NULL)
                a->prev->next = b;

        if (b->next != NULL)
                b->next->prev = a;

        a->next = b->next;
        b->prev = a->prev;
        a->prev = b;
        b->next = a;

	if (*list == a)
		*list = b;
}
