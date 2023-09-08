#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array and initializes it to zero.
 * @nmemb: Number of members.
 * @size: Size of each member.
 *
 * Return: Pointer to the newly allocated space in memory or NULL on failure.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i, total_size;

	/* If nmemb or size is 0, return NULL */
	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	total_size = nmemb * size;

	/* Allocate memory */
	ptr = malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}

	/* Initialize memory to zero */
	for (i = 0; i < total_size; i++)
	{
		ptr[i] = 0;
	}

	return (ptr);
}
