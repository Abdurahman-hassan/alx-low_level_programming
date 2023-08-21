# include "main.h"

/**
  * _strlen - return the length of string
  * @*s: the pointer to the first char in arr
  * Return: the length
  */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;

	return (len);
}
