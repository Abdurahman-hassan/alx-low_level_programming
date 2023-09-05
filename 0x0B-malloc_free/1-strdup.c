#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string by allocating a new space in memory.
 *
 * @str: the string to duplicate.
 *
 * Return: pointer to the duplicated string if successful,
 *		   NULL if the string is NULL or if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	/* Determine the length of the string */
	while (str[len])
	{
		len++;
	}

	/* Allocate memory for the new string + null terminator */
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}

	/* Copy the characters */
	for (i = 0; i < len; i++)
	{
		dup[i] = str[i];
	}

	/* Add the null terminator */
	dup[len] = '\0';

	return (dup);
}
