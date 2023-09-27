#include "lists.h"

/**
 * print_listint_safe - prints a linked list, safely
 * @head: list of type listint_t to print
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0; /* Counter for the number of nodes printed */

	if (!head)
		return (0);

	tortoise = hare = head;

	/* Check if a cycle exists */
	while (hare && hare->next)
	{
		if (count > 0 && tortoise == hare)
			break;

		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		tortoise = tortoise->next;
		hare = hare->next->next;
		count++;

		/* If hare and tortoise meet, cycle detected */
		if (tortoise == hare && count > 0)
		{
			printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);
			break;
		}
	}

	/* If no cycle was detected, print remaining nodes */
	while (count == 0 && tortoise)
	{
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		tortoise = tortoise->next;
		count++;
	}

	return (count);
}
