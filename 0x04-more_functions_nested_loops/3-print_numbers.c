# include "main.h"

/**
  * print_numbers - print the numbers from 0 to 9
  * seperated with new line
  *
  * Return 0 if success
  */
void print_numbers(void)
{
	int i = 0;

	while (i < 10)
	{
		_putchar('0' + i);
		i++;
	}

	_putchar('\n');
}
