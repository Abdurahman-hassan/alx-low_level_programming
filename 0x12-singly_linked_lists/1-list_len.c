#include "lists.h"
#include <stdio.h>

/**
 * list_len - Returns the number of elements in a list_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of elements in the linked list.
 */
size_t list_len(const list_t *h)
{
	/* Initialize a counter for the number of nodes. */
	size_t nodes = 0;

	/* Iterate through the list until we reach a NULL node. */
	while (h)
	{
		nodes++;  /* Increment the node counter. */
		h = h->next;  /* Move to the next node in the list. */
	}
	return (nodes);
}
