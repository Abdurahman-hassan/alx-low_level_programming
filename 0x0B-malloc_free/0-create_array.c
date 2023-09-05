#include "main.h"
#include <stdlib.h>

/**
 * create_array - Dynamically allocates memory for an array and initializes it.
 *
 * Description: This function tries to allocate memory for an array of chars.
 *		If successful, it populates each element with a given char.
 *		Useful when needing a buffer initialized with a default char.
 *
 * @size:	Desired number of elements for the array. Returns NULL if 0.
 * @c:		Character to initialize each element of the array with.
 *
 * Return:	On success, pointer to the first element of the array. Returns NULL
 *		if allocation failed or size is 0.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	array = malloc(size * sizeof(char)); /* Try allocating required memory */

	if (array == NULL) /* If allocation fails, return NULL */
	{
		return (NULL);
	}

	for (i = 0; i < size; i++) /* Populate array with specified char */
	{
		array[i] = c;
	}

	return (array);
}
