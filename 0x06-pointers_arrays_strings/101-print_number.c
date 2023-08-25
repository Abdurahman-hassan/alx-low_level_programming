# include "main.h"

/**
  * print_number - function that prints an integer with recursion
  * and putchar only
  * @n: the number that will print
  * Return: void
  */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10)
	{
		/* it will be stop when n ==0 */
		print_number(n / 10);
	}

	_putchar((n % 10) + '0');
}
