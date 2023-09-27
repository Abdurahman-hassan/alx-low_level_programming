#include "lists.h"

/**
 * free_auxlist - frees an auxiliary linked list.
 * @aux_head: head of the auxiliary list.
 *
 * Return: no return.
 */
void free_auxlist(aux_list_t **aux_head)
{
	aux_list_t *temp_node;
	aux_list_t *current_node;

	if (aux_head != NULL)
	{
		current_node = *aux_head;
		while ((temp_node = current_node) != NULL)
		{
			current_node = current_node->next;
			free(temp_node);
		}
		*aux_head = NULL;
	}
}

/**
 * print_listint_safe - prints a linked list.
 * @head: head of the list.
 *
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;
	aux_list_t *aux_h, *aux_new, *aux_current;

	aux_h = NULL;
	while (head != NULL)
	{
		aux_new = malloc(sizeof(aux_list_t));

		if (aux_new == NULL)
			exit(98);

		aux_new->address = (void *)head;
		aux_new->next = aux_h;
		aux_h = aux_new;

		aux_current = aux_h;

		while (aux_current->next != NULL)
		{
			aux_current = aux_current->next;
			if (head == aux_current->address)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_auxlist(&aux_h);
				return (node_count);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		node_count++;
	}

	free_auxlist(&aux_h);
	return (node_count);
}
