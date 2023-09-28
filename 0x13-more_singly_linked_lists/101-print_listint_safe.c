#include "lists.h"

/**
 * find_loop_start - find the start node of loop using Floyd's algorithm
 * @head: pointer to head of list
 * Return: start node of loop or NULL
 */
listint_t *find_loop_start(listint_t *head)
{
	listint_t *tortoise, *hare;

	tortoise = hare = head;

	/* Detect a loop using the Floyd's cycle detection algorithm */
	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			return (hare);
		}
	}

	return (NULL);
}

/**
 * print_listint_safe - prints a linked list, safely
 * @head: list of type listint_t to print
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	listint_t *loop_start;

	loop_start = find_loop_start((listint_t *)head);

	if (!loop_start)
	{
		/* No loop in the list */
		while (head)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			count++;
			head = head->next;
		}
	}
	else
	{
		/* List has a loop */
		while (head != loop_start)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			count++;
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);/* Start of the loop */
		count++;
		head = head->next;

		while (head != loop_start)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			count++;
			head = head->next;
		}
	}

	return (count);
}

