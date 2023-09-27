#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n)
 * of a listint_t linked list.
 * @head: pointer to the start of the list.
 *
 * Return: the sum of all data in the list or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;  /* Initialize sum to 0 */

	/* Traverse the list, accumulating the sum of the data */
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

