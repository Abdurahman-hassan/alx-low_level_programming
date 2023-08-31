#include "main.h"

/**
 * wildcmp_recursion - A helper function
 * to recursively compare the two strings.
 * @s1: The first string.
 * @s2: The second string with wildcards.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp_recursion(char *s1, char *s2)
{
	/* Base case: Both strings are at the end */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If the characters match, move on to the next character in both strings */
	if (*s1 == *s2)
		return (wildcmp_recursion(s1 + 1, s2 + 1));

	/* If there's a wildcard in s2 */
	if (*s2 == '*')
	{
		/* If the next character is also a wildcard, skip it */
		if (*(s2 + 1) == '*')
			return (wildcmp_recursion(s1, s2 + 1));

		/* Two recursive calls: */
		 /* 1) Treat wildcard as empty and move */
		 /* to next character in s2. */
		 /* 2) Use wildcard to replace the character */
		 /* in s1 and move to next character in s1. */

		if (wildcmp_recursion(s1 + 1, s2) || wildcmp_recursion(s1, s2 + 1))
			return (1);
	}
	return (0);
}

/**
 * wildcmp - Compares two strings
 * and checks if they can be considered identical.
 * @s1: The first string.
 * @s2: The second string which can contain the wildcard '*'.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_recursion(s1, s2));
}
