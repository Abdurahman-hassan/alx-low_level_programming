# include "main.h"

/**
  * print_square - prints a square, followed by a new line
  * @size: is the number of square
  * Return: 0 if success
  */
void print_square(int size)
{
	int outterSqure, innerSqure;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (outterSqure = 0; outterSqure < size; outterSqure++)
	{
		for (innerSqure = 0; innerSqure < size; innerSqure++)
		{
			_putchar('#');
		}

		_putchar('\n');
	}
}
