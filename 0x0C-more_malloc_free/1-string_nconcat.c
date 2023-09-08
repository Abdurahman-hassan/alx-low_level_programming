#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings using at most n bytes from s2.
 * @s1: First string.
 * @s2: Second string.
 * @n: Maximum number of bytes to use from s2.
 *
 * Return: Pointer to the newly allocated space in memory containing the
 * concatenated strings. If the function fails, return NULL.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *new_str;

	/* If NULL is passed, treat it as an empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of s1 and s2 */
	while (s1[len1])
		len1++;
	while (s2[len2] && len2 < n)
		len2++;

	/* If n >= len2, use the entire s2 */
	if (n >= len2)
		len2 = len2;
	else
		len2 = n;

	/* Allocate memory for the concatenated string */
	new_str = malloc((len1 + len2 + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);

	/* Copy s1 into the new string */
	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	/* Concatenate s2 to the new string */
	for (j = 0; j < len2; j++, i++)
		new_str[i] = s2[j];

	/* Null-terminate the new string */
	new_str[i] = '\0';

	return (new_str);
}
