#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Pointer to the start of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	/* Initialize a counter for the number of nodes. */
	size_t nodes = 0;

	/* Iterate through the list until we reach a NULL node. */
	while (h)
	{
		/* Check if the current node's str attribute is NULL. */
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%lu] %s\n", h->len, h->str);

		h = h->next;  /* Move to the next node in the list. */
		nodes++;  /* Increment the node counter. */
	}
	return (nodes);
}
