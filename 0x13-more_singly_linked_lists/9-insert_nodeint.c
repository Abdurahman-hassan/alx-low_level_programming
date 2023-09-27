#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Double pointer to the head of the list.
 * @idx: Index where the new node should be added, starts at 0.
 * @n: Integer data for the new node.
 * Description: If the function fails or it's not possible to insert at
 *              the specified index, it returns NULL. Otherwise, it inserts
 *              the node and returns its address.
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;     /* New node to insert */
	listint_t *current = *head; /* Pointer to traverse the list */
	unsigned int i = 0;         /* Counter for index */

	/* Allocate memory for new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	/* If inserting at the beginning */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Traverse to the idx or the end of the list */
	while (current && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	/* If idx is out of bounds */
	if (!current)
	{
		free(new_node);
		return (NULL);
	}

	/* Insert the new node */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}

