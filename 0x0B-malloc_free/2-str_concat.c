#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: First string.
 * @s2: Second string.
 * Return: Pointer to the newly allocated space in memory,
 *		   which contains s1 followed by s2 and null terminated.
 *		   If function fails, it should return NULL.
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Handling NULL strings */
	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	/* Determine the lengths of the strings */
	while (s1[len1])
	{
		len1++;
	}
	while (s2[len2])
	{
		len2++;
	}
	/* Allocate memory for the concatenated string + null terminator */
	concat = malloc((len1 + len2 + 1) * sizeof(char));
	if (concat == NULL)
	{
		return (NULL);
	}
	/* Copy the characters of s1 */
	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}
	/* Copy the characters of s2 */
	for (j = 0; j < len2; j++, i++)
	{
		concat[i] = s2[j];
	}
	/* Add the null terminator */
	concat[i] = '\0';
	return (concat);
}
