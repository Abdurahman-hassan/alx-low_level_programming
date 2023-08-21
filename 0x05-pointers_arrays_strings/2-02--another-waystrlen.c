# include "main.h"

/**
  * _strlen - return the length of string
  * @*s: the pointer to the first char in arr
  * Return: the length
  */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
