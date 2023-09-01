# include "main.h"

/**
  * _strpbrk - function that searches a string for any of a set of bytes.
  * The _strpbrk() function locates the first occurrence
  * in the string s of any of the bytes in the string accept
  * @s: the main string
  * @accept: the string that will look for the first match string
  * Return: a pointer to the byte in s that matches
  * one of the bytes in accept, or NULL if no such byte is found
  */
char *_strpbrk(char *s, char *accept)
{
	for (; *s != '\0'; s++)
	{
		char *a;

		for (a = accept; *a != '\0'; a++)
		{
			if (*s == *a)
				break;
		}
  /* If we didn't reach the end of 'accept', then a match was found */
		if (*a != '\0')
			return (s);
	}

	return ('\0');
}
