#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a specified index.
 * @head: Double pointer to the head of the list.
 * @index: Index of the node to be deleted, starts at 0.
 *
 * Description: If the function succeeds in deleting the node, it returns 1.
 * If the deletion fails or the index is out of bounds, it returns -1.
 * Return: 1 if successful, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	current = *head;

	/* If the node to be deleted is the first node */
	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	/* Traverse the list to get to the node before the one to be deleted */
	for (i = 0; i < index - 1; i++)
	{
		if (!current)
			return (-1);
		current = current->next;
	}

	/* If index is out of bounds */
	if (!current || !current->next)
		return (-1);

	/* Deleting the node */
	temp = current->next;
	current->next = temp->next;
	free(temp);
	return (1);
}
