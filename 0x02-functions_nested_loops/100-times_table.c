#include "main.h"

/**
  * print_times_table - prints the n times table, starting with 0
  *
  * @n: this is the checker number
  * Return: 0 if success
  */
void print_times_table(int n)
{
	int i, j, result;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			result = i * j;

			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');

				if (result < 10)
					_putchar(' ');
				if (result < 100)
					_putchar(' ');
			}

			if (result >= 100)
			{
				_putchar('0' + result / 100);
				_putchar('0' + (result / 10) % 10);
			}
			else if (result >= 10)
			{
				_putchar('0' + result / 10);
			}
			_putchar('0' + result % 10);
		}
		_putchar('\n');
	}
}
