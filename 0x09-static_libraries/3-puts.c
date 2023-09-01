# include "main.h"

/**
  * _puts - function that prints a string, followed by a new line, to stdout
  * @str: the string that will be print
  * Return: void
  */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
