# include "main.h"

/**
  * print_most_numbers - print numbers from 0 -9
  * don't print 2,4
  * Return: 0 if success
  */
void print_most_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i == 2 || i == 4)
			continue;
		_putchar('0' + i);
	}

	_putchar('\n');
}
