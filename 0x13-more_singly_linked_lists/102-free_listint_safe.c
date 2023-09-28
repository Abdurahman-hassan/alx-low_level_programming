#include "lists.h"
#include <stdlib.h>

size_t looped_listint_len(const listint_t *head);

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: A pointer to the address of the head of the list.
 *
 * Return: The size of the list that was free’d.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0, loop_nodes = 0;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	loop_nodes = looped_listint_len(*h);

	while (*h && (loop_nodes == 0 || count < loop_nodes))
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}

	*h = NULL; /* Set the head to NULL */

	return (count);
}

/**
 * looped_listint_len - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tortoise = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
				hare = hare->next;
			}

			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				nodes++;
				tortoise = tortoise->next;
			}

			return (nodes);
		}

		tortoise = tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}


