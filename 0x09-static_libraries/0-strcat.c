# include "main.h"

/**
  * _strcat - function that concatenates two strings
  * @dest: the final concating string
  * @src: the string that will concat with dest
  * Return: a pointer to the resulting string dest
  */
char *_strcat(char *dest, char *src)
{
	int dest_length = 0, i;

	while (dest[dest_length])
	{
		dest_length++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_length + i] = src[i];
	}

	dest[dest_length + i] = '\0';

	return (dest);
}
