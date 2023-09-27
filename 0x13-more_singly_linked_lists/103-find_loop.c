#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a listint_t linked list.
 * @head: The head of the linked list.
 *
 * Return: The address of the node
 * where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	if (!head)
		return (NULL);

	tortoise = hare = head;

	/* Phase 1: Check if a cycle exists */
	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)  /* Cycle detected */
			break;
	}

	if (tortoise != hare)
		return (NULL);  /* No cycle */

	/* Phase 2: Find the start of the cycle */
	tortoise = head;  /* Reinitialize tortoise to head */

	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}
	/* or tortoise, as they now both point to the start of the cycle */
	return (hare);
}
