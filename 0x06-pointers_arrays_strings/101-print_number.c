# include "main.h"

/**
  * print_number - function that prints an integer with recursion
  * and putchar only
  * @n: the number that will print
  * Return: void
  */
void print_number(int n)
{
	unsigned int unsignedInteger;
	if (n < 0)
	{
		_putchar('-');
		unsignedInteger = -n;
	}
	else
	{
		unsignedInteger = n;
	}

	if (unsignedInteger / 10)
	{
		/* it will be stop when n ==0 */
		print_number(unsignedInteger / 10);
	}

	_putchar((unsignedInteger % 10) + '0');
}
