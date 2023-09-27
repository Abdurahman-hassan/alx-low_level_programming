#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list in a safe way.
 * This function can print lists with a loop.
 * @head: The head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	/* Using Floyd's cycle detection algorithm: */
	/* slow and fast pointers to traverse the list */
	const listint_t *slow = head, *fast = head;
	size_t count = 0; /* To count the number of nodes printed */

	/* Exit with status 98 if head is NULL */
	if (!head)
		exit(98);

	/* Traverse the list using the tortoise and hare approach */
	while (fast && fast->next)
	{
		/* Print the current node and move to the next */
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;

		slow = slow->next;    /* Move slow pointer one step */
		fast = fast->next->next; /* Move fast pointer two steps */

		/* Detect a loop if the slow and fast pointers meet */
		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			/* Return count, with addition for loop detection */
			return (count + 1);
		}
	}

	/* If no loop detected, continue printing the rest of the list */
	while (slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
	}

	return (count); /* Return the number of nodes printed */
}

