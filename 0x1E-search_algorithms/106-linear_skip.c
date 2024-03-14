#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer to the first node where value is located, or NULL on failure
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *next;

	if (list == NULL)
		return (NULL);
	prev = list;
	next = list->express;
	while (next != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", next->index, next->n);
		if (next->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", prev->index, next->index);
			break;
		}
		prev = next;
		next = next->express;
	}
	if (next == NULL)
	{
		prev = list;
		while (prev->next != NULL)
			prev = prev->next;
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index, prev->index);
	}
	while (prev != NULL && prev->index <= next->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
