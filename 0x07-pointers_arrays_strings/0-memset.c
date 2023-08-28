# include "main.h"

/**
  * _memset - this function fills memory with a constant byte.
  * The _memset() function fills the first n bytes of the memory
  * area pointed to by s with the constant byte b
  * @s: array that will point to
  * @b: the data will be fill into @s
  * @n: the number of bytes that will be fill
  * Return: a pointer to the memory area s
  */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
