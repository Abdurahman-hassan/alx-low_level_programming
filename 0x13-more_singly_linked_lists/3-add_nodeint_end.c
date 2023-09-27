#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: double pointer to the head of the list
 * @n: integer to be included in the new node
 *
 * Return: address of the new element, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *temp;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;       /* Set the data for the new node */
	new_node->next = NULL; /* This will be the last node, so next will be NULL */

	/* If the list is empty, the new node is the head */
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		/* Traverse the list till the last node */
		temp = *head;
		while (temp->next)
		{
			temp = temp->next;
		}
		/* Point the last node to the new node */
		temp->next = new_node;
	}

	return (new_node);
}
