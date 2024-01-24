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
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;
    listint_t *temp;

    while (current != NULL)
    {
        temp = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            current->prev->next = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;

            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;

            if (current->prev == NULL)
                *list = current;
            else
                current->prev->next = current;

            print_list(*list);
        }

        current = temp;
    }
}
