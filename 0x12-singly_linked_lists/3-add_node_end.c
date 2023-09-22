#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: The string to be inserted.
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *temp;
	size_t len = 0;

	new_node = malloc(sizeof(list_t)); /* Allocate memory for the new node */
	if (new_node == NULL)
		return (NULL); /* Memory allocation failed */

	/* Duplicate the provided string to avoid referencing outside data */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		/* Clean up in case strdup fails */
		free(new_node);
		return (NULL);
	}

	/* Calculate the length of the string for len property of the list */
	while (str[len])
		len++;

	/* Assign calculated length and initialize the next pointer to NULL */
	new_node->len = len;
	new_node->next = NULL;

	/* If the list is currently empty, set the new node as the head */
	if (*head == NULL)
		*head = new_node;
	else
	{
		/* If list is not empty, traverse to the end */
		temp = *head;
		while (temp->next)
			/* Navigate through nodes until reaching the last one */
			temp = temp->next;
		/* Set the next of the last node to the new node */
		temp->next = new_node;
	}

	/* Return the newly added node */
	return (new_node);
}
