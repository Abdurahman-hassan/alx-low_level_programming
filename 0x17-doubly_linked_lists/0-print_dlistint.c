#include "lists.h"

/**
* size_t print_dlistint - prints all the elements of a dlistint_t list
* @h: pointer to head of list
* Return: number of nodes
*/
size_t print_dlistint(const dlistint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        ++count;
        printf("%d\n", h->n);
        h = h->next;
    }
    return (count);
}