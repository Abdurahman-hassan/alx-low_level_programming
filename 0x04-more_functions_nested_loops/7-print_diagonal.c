# include "main.h"

/**
  * print_diagonal - draws a straight line in the terminal
  * f n is 0 or less, the function should only print \n
  * @n: The numbers of print_diagonal
  * Return: 0 if success
  */
void print_diagonal(int n)
{

	int diagonal = 0;
	int nestedDiagonal;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	while (diagonal < n)
	{
		nestedDiagonal = 0;

		while (nestedDiagonal < diagonal)
		{
			_putchar(' ');
			nestedDiagonal++;
		}
		_putchar('\\');
		_putchar('\n');
		diagonal++;
	}
}
