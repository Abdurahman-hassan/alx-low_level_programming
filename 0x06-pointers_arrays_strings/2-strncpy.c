# include "main.h"

/**
  * _strncpy -  function that copies a string
  * @dest: The string that will copy to
  * @src: the string that will copy from
  * @n: the number of byts
  * Return: string that have src with dest content
  */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
