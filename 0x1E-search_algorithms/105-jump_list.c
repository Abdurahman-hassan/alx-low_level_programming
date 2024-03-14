#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers using the
 * Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 * Return: a pointer to the first node where value is located, or NULL on failure
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t i, jump;
	listint_t *prev, *next;

	if (list == NULL)
		return (NULL);
	jump = 0;
	while (jump < size && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", jump, list->n);
		prev = list;
		list = list->next;
		jump += sqrt(size);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", jump - (unsigned int)sqrt(size), jump);
	if (jump >= size)
		jump = size - 1;
	for (i = jump - (unsigned int)sqrt(size); i <= jump; i++)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
