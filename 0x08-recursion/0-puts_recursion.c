# include "main.h"

/**
  * _puts_recursion - function that prints a string, followed by a new line.
  * @s: this is the string that we will use in put to print
  * Return: void
  */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}
