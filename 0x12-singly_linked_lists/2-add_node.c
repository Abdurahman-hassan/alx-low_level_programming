#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: The string to be inserted.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	size_t len = 0;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Duplicate the string */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Calculate the length of the string */
	while (str[len])
	{
		len++;
	}

	/* Assign values to the new node */
	new_node->len = len;
	new_node->next = *head;

	/* Make the new node as the head of the list */
	*head = new_node;

	return (new_node);
}

