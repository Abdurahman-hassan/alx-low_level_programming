#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: index of the list where the new node should be added
 * @n: data to be added to the new node
 *
 * Return: the address of the new node, or NULL if it failed
 *         if it is not possible to add the new node at index idx,
 *         do not add the new node and return NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
 dlistint_t *new_node, *current = *h;
 unsigned int i = 0;

 if (!h)
  return (NULL);
 if (idx == 0)
  return (add_dnodeint(h, n));
 while (current && i < idx - 1)
 {
  current = current->next;
  i++;
 }
 if (!current)
  return (NULL);
 if (!current->next)
  return (add_dnodeint_end(h, n));
 new_node = malloc(sizeof(dlistint_t));
 if (!new_node)
  return (NULL);
 new_node->n = n;
 new_node->next = current->next;
 new_node->prev = current;
 current->next->prev = new_node;
 current->next = new_node;
 return (new_node);
}
