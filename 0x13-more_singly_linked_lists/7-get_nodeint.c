#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the start of the list.
 * @index: index of the node, starting at 0.
 *
 * Return: the nth node or NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	/* Traverse the list until the desired index or end of the list */
	while (head != NULL)
	{
		/* If count matches the index, return the current node */
		if (count == index)
			return (head);

		/* Move to the next node and increment count */
		head = head->next;
		count++;
	}

	/* Return NULL if the node does not exist */
	return (NULL);
}
