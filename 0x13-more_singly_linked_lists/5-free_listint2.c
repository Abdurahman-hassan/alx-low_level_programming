#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a listint_t list, sets the head to NULL
 * @head: double pointer to the start of the list
 *
 * Description:
 * This function traverses a singly linked list and releases memory
 * used by each node. By the end, it ensures the head points to NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp; /* Temp pointer to traverse without losing head */

	/* If head is NULL, there's nothing to free. Return. */
	if (!head)
		return;

	/* Traverse the list while the current node isn't NULL */
	while (*head)
	{
		tmp = *head;    /* Save current node pointer */
		*head = (*head)->next; /* Move to the next node */
		free(tmp);      /* Free current node */
	}

	/* Set head pointer to NULL after freeing entire list */
	*head = NULL;
}
