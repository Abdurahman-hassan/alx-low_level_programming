# include "main.h"

/**
  * print_chessboard - function that prints the chessboard.
  * @a: the 2D char array representing the chessboard
  * Return: void
  */
void print_chessboard(char (*a)[8])
{
	int i, j, len = 0;

	while (a[len])
		len++;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}

		_putchar('\n');
	}
}
