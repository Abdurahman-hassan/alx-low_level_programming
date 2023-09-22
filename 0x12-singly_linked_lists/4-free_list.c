#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the head of the list.
 */
void free_list(list_t *head)
{
	list_t *temp;

	/* Traverse the list */
	while (head != NULL)
	{
		temp = head;        /* Store the current node in a temporary variable */
		head = head->next;  /* Move to the next node */
		free(temp->str);    /* Free the duplicated string */
		free(temp);         /* Free the current node */
	}
}

