#include "lists.h"

/**
 * detect_loop - Detects if there is a loop in the list.
 * @head: The head of the list.
 *
 * Return: The start node of the loop or NULL.
 */
const listint_t *detect_loop(const listint_t *head)
{
	/* Pointers for detecting loop using Floyd's Cycle-Finding algorithm */
	const listint_t *slow = head, *fast = head;

	/* To store the starting node of the detected loop, if present */
	const listint_t *loop_start = NULL;

	/* Traverse the list looking for a loop */
	while (fast && fast->next)
	{
		slow = slow->next; /* Move the slow pointer one step */
		fast = fast->next->next; /* Move the fast pointer two steps */

		/* If both pointers meet, there's a loop */
		if (slow == fast)
		{
			loop_start = slow; /* Save the meeting point */
			break;
		}
	}

	/* If a loop is detected, find its starting point */
	if (loop_start)
	{
		slow = head; /* Reset slow pointer to the beginning of the list */
		while (slow != fast)
		{
			fast = fast->next; /* Move fast pointer one step */
			if (slow == fast)
			{
				loop_start = slow; /* Mark the loop start */
				break;
			}
			slow = slow->next; /* Move slow pointer one step */
		}
	}

	return (loop_start); /* Return the loop's starting node or NULL if no loop */
}

/**
 * print_listint_safe - Prints a listint_t list in a safe way.
 * @head: The head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	/* Counter for the number of nodes printed */
	size_t count = 0;

	/* Detect loop in the list */
	const listint_t *loop_start = detect_loop(head);

	/* If list is empty, exit with an error code */
	if (!head)
		exit(98); /* Convention for a detected failure */

	/* Print nodes until the loop's start, or until the list ends */
	while (head != loop_start)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++; /* Increment the node count */
		head = head->next; /* Move to the next node */
	}

	/* If a loop is detected, print the loop's starting node */
	if (loop_start)
	{
		printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);
		count++; /* Increment the node count */
	}

	return (count); /* Return the total count of printed nodes */
}
