#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current;
    listint_t *prev;
    listint_t *temp;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current;
        prev = current->prev;

        while (prev != NULL && prev->n > temp->n)
        {
            /* Swap nodes */
            if (temp->next != NULL)
                temp->next->prev = prev;
            prev->next = temp->next;
            temp->prev = prev->prev;
            temp->next = prev;
            if (prev->prev != NULL)
                prev->prev->next = temp;
            prev->prev = temp;

            /* If temp was the head, update the list pointer */
            if (temp->prev == NULL)
                *list = temp;

            print_list(*list);

            prev = temp->prev;
        }

        current = current->next;
    }
}
