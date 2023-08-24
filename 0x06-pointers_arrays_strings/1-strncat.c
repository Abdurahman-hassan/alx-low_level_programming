# include "main.h"

/**
  * _strncat - function that concatenates two strings
  * @dest: the final concating string
  * @src: the string that will concat with dest
  * @n: size of bytes
  * Return: a pointer to the resulting string dest
  */
char *_strncat(char *dest, char *src, int n)
{
	int dest_length = 0, i;

	while (dest[dest_length])
	{
		dest_length++;
	}

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_length + i] = src[i];

	if (n <= 0)
		dest[dest_length + i] = '\0';

	return (dest);
}
