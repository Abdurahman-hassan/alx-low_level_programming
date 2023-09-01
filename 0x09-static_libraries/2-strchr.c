# include "main.h"

/**
  * _strchr - function that locates a character in a string.
  * @s: the main string that will look into
  * @c: the main char that will look for
  * Return: a pointer to the first occurrence of the character c
  * in the string s, or NULL if the character is not found
  */
char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}
	 /* If c is the null terminator, return a pointer to it */
	if (c == '\0')
		return (s);

	 /* If the loop completes without finding the character, return NULL */
	return ('\0');
}
