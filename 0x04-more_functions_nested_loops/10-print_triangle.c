# include "main.h"

/**
  * print_triangle - function that prints a triangle, followed by a new line
  * @size: this is the size of triangle
  * If size is 0 or less, the function should print only a new line
  * Return: 0 if success
  */
void print_triangle(int size)
{
	int hashes, spaces, main;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (main = 1 ; main <= size; main++)
	{
		for (spaces = size - 1; spaces >= main; spaces--)
		{
			_putchar(' ');

		}

		for (hashes = 1; hashes <= main; hashes++)
		{
			_putchar('#');

		}

		_putchar('\n');
	}
}
