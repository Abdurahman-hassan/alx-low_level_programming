#include "main.h"

/**
 * print_number - Recursively prints an integer.
 * @n: Integer to be printed.
 */
void print_number(int n)
{
	unsigned int n1;

	/* Convert negative numbers to positive and print the negative sign. */
	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
	{
		n1 = n;
	}

	/* If there's more than one digit, print the higher order digit(s). */
	if (n1 / 10)
	{
		print_number(n1 / 10);
	}

	/* Print the least significant digit. */
	_putchar((n1 % 10) + '0');
}

