#include "main.h"

/**
 * print_number - Print an integer
 *
 * @n: The integer to be printed
 * Return: void
 */
void print_number(int n)
{
	/* Handle negative numbers by printing '-' and making the number positive */
	if (n < 0)
	{	
		n = -n;
		_putchar('-');
	}
	else
	{
		n = n;
	}

	/* Print the digits recursively */
	if (n / 10)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}

