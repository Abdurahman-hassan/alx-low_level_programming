#include "main.h"

/**
  * print_number - to print the integer numbers
  * @n: is the number to check
  * Return: the integer
  */
void print_number(int n)
{
	/* Handle the special edge case for the smallest negative integer */
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		n = 147483648;
	}

	/* If the number is negative, print '-' and use positive part */
	else if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	/* Recursively print the number */
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}
