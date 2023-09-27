#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Double pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	while (*head)
	{
		next = (*head)->next;  /* Preserve the next node */
		(*head)->next = prev;  /* Point current node's next to previous */
		prev = *head;          /* Update previous to current node */
		*head = next;          /* Move to next node */
	}

	*head = prev;  /* Head now points to last node in the list (new first) */

	return (*head);
}

