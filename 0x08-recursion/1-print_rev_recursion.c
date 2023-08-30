# include "main.h"

/**
  * _print_rev_recursion - function that prints a string in reverse.
  * @s: the string that will be print
  * Return: void
  */
void _print_rev_recursion(char *s)
{
	/* If the string has ended, just return */
	if (*s == '\0')
	{
		return;
	}

	/* Recursively call the function for the next character */
	_print_rev_recursion(s + 1);

	/* Once the end is reached and we start returning, print each character */
	_putchar(*s);
}
