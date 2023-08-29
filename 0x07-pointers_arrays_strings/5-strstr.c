#include "main.h"

/**
 * _strstr - function that locates a substring.
 * The _strstr() function finds the first occurrence of the substring
 * needle in the string haystack.
 * The terminating null bytes (\0) are not compared.
 * @haystack: the main string to be searched
 * @needle: the substring to search for
 * Return: a pointer to the beginning of the located substring,
 * or '\0' if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	/** Declare and initialize loop counters */
	int i, j;

	/** If needle is an empty string, return haystack. */
	if (!needle[0])
		return (haystack);

	/** Loop through each character in haystack */
	for (i = 0; haystack[i]; i++)
	{
		/* Check if the characters */
		/* from the current position match needle */
		/* continue if the condition is valid break if not valid */

		for (j = 0; needle[j] && (haystack[i + j] == needle[j]); j++)
			;

		/* If we've found the entire needle */
		/* return a pointer to its location in haystack */
		/* \0 is fasle not false is true if true return the adress */
		if (!needle[j])
			return (&haystack[i]);
	}

	/** If no match is found, return '\0' */
	return ('\0');
}
