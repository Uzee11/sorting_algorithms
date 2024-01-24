#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *lead, *follow, *new, *temp;

    if (!list || !(*list) || !((*list)->next))
        return;

    lead = (*list)->next;
    follow = (*list);

    while (lead)
    {
        new = lead->next;

        while (follow && lead->n < follow->n)
        {
            if (follow->prev)
                follow->prev->next = lead;
            else
                *list = lead;

            if (lead->next)
                lead->next->prev = follow;

            temp = lead->next;
            lead->next = follow;
            lead->prev = follow->prev;
            follow->next = temp;
            follow->prev = lead;

            print_list(*list);

            follow = lead->prev;
        }

        lead = new;
        if (lead)
            follow = lead->prev;
    }
}
