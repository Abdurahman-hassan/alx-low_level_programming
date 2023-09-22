#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>
/**
 * struct list_s - Singly linked list structure
 * @str: Pointer to a string - the string data of the node.
 * @len: The length of the string `str`.
 * @next: Pointer to the next node in the list.
 *
 * Description: This structure defines the attributes of a node
 * in a singly linked list. Each node stores a string `str`,
 * the length of the string `len`, and a pointer to the next node `next`.
 */
typedef struct list_s
{
	char *str;
	size_t len;
	struct list_s *next;
} list_t;

/* prototype functions*/

size_t print_list(const list_t *h);






#endif /* LISTS_H */
