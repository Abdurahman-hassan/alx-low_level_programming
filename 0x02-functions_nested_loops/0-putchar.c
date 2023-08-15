# include "main.h"

/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  *
  * Return: On succcess 1.
  * On error, -1 is returned, and errno is set apprapriately.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
