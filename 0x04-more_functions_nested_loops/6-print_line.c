# include "main.h"

/**
  * print_line - draws a straight line in the terminal
  * f n is 0 or less, the function should only print \n
  * @n: The numbers of lines
  * Return: 0 if success
  */
void print_line(int n)
{
	int line = 0;

	while (line < n)
	{
		if (n <= 0)
			_putchar('\n');
		_putchar('_');
		line++;
	}

	_putchar('\n');
}
