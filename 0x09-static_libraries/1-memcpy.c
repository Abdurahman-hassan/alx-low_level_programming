# include "main.h"

/**
  * _memcpy - function that copies memory area.
  * The _memcpy() function copies n bytes from memory area
  * src to memory area dest
  * @dest: the char that will copy to
  * @src: the char that will copy from
  * @n: number of bytes
  * Return: a pointer to dest
  */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
