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
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to a pointer to head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *loop_start, *next_node;

	if (!h || !*h)
		return (0);

	loop_start = find_loop_start(*h);

	while (*h && (loop_start != *h || count == 0))
	{
		next_node = (*h)->next;
		free(*h);
		*h = next_node;
		count++;

		/* If we've detected a loop, we want to stop */
		/* once we circle back to the start of the loop. */
		if (*h == loop_start && count != 0)
			break;
	}

	*h = NULL; /* Set the head to NULL */
	return (count);
}

