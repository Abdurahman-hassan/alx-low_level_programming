#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc and checks for errors.
 * @b: Size of memory to be allocated.
 *
 * Description: This function attempts to allocate memory of a specified size.
 *              If the memory allocation fails, the function terminates the
 *              program with a status value of 98. If successful, the function
 *              returns a pointer to the allocated memory.
 *
 * Return: Pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	/* Allocate memory of size b */
	void *ptr = malloc(b);

	/* Check if memory allocation was successful */
	if (ptr == NULL)
	{
		/* Terminate the program if allocation failed */
		exit(98);
	}

	/* Return pointer to allocated memory */
	return (ptr);
}
