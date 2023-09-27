#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: double pointer to the start of the list
 *
 * Return: the head node’s data (n) or 0 if linked list is empty.
 */
int pop_listint(listint_t **head)
{
	int data;            /* Temporary variable to store data of head */
	listint_t *temp;     /* Temporary node pointer for freeing */

	/* Return 0 if the list is empty */
	if (!head || !*head)
		return (0);

	/* Save the data from the head node */
	data = (*head)->n;
	temp = *head;

	/* Update head to point to the next node */
	*head = (*head)->next;

	/* Free the old head node */
	free(temp);

	return (data);
}
