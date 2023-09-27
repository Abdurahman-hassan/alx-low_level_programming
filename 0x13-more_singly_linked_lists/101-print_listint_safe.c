#include "lists.h"

/**
 * print_listint_safe - prints a linked list, safely
 * @head: list of type listint_t to print
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;   /* Counter for the number of nodes printed */
	/* To calculate the difference between current and next node addresses */
	long int diff;

	while (head)
	{
		diff = head - head->next;
		count++;  /* Increment the node count */
		printf("[%p] %d\n", (void *)head, head->n);

		if (diff > 0)
		/* Move to the next node if progressing normally */
			head = head->next;
		else
		{
			/* Detect the loop and print the loop's starting node */
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;  /* Exit the loop */
		}
	}

	return (count);  /* Return the total count of printed nodes */
}
