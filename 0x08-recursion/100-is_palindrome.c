#include "main.h"

/**
 * _strlen_recursion - Calculate and return the length
 * of a string using recursion.
 * @s: The string whose length is to be calculated.
 *
 * Return: The length of the string @s.
 */
int _strlen_recursion(char *s)
{
	/* Base case: If the string has reached its end */
	if (*s == '\0')
		return (0);

	/* Recursion: Move to the next character and add 1 to the length */
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - Recursively
 * check if a segment of a string is a palindrome.
 * @s: The string to be checked.
 * @start: The starting index of the segment in the string.
 * @end: The ending index of the segment in the string.
 *
 * Return: 1 if the segment is a palindrome, otherwise 0.
 */
int check_palindrome(char *s, int start, int end)
{
	/* Base case: If the start index has surpassed or met the end index */
	if (start >= end)
		return (1);

	/* Check if the characters at the current indices are the same */
	if (s[start] != s[end])
		return (0);

	/* Recursion: Move to the next set of characters inward */
	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - Check if a string is a palindrome.
 * @s: The string to be checked.
 *
 * Return: 1 if the string is a palindrome, otherwise 0.
 */
int is_palindrome(char *s)
{
	/* Find the length of the string */
	int len = _strlen_recursion(s);

	/* Check if the string is a palindrome from the first to the last character */
	return (check_palindrome(s, 0, len - 1));
}
