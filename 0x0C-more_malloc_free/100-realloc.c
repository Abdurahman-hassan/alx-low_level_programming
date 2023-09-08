#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size, in bytes, of the allocated space for ptr.
 * @new_size: The new size, in bytes of the new memory block.
 * Return: Pointer to the newly allocated memory, or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i,  min_size;

	if (new_size == old_size)
	{
		/* If they're the same, there's no need to reallocate, */
		/* just return the original pointer. */
		return (ptr);
	}
	/* If the pointer provided is NULL, this means we are just allocating*/
	/* a new space equivalent to calling malloc with the new size. */
	if (!ptr)
	{
		return (malloc(new_size));
	}
	/* If the new size is 0 and the pointer is not NULL, */
	/* this is equivalent to freeing the pointer and returning NULL. */
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	/* If allocation fails, return NULL. */
	if (!new_ptr)
	{
		return (NULL);
	}
	/* We want to copy over the contents from the original pointer */
	/* to the new pointer. However, we only need to copy up to the minimum */
	/* of the old and new sizes. This prevents out-of-bounds memory access. */
	min_size = (old_size < new_size) ? old_size : new_size;
	/* Iterate through each byte to min_size and copy from old to new ptr. */
	for (i = 0; i < min_size; i++)
	{
		new_ptr[i] = ((char *)ptr)[i];
	}
	free(ptr);
	/* Return the new pointer which now holds the data from the original*/
	return (new_ptr);
}
