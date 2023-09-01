# include "main.h"

/**
  * _strcpy - function that copies the string pointed to by src,
  * including the terminating null byte (\0), to the buffer pointed to by dest.
  * @dest: this will copied into
  * @src: the string that will be copy
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	/* the last char should be \0 */
	dest[i] = '\0';

	return (dest);
}
