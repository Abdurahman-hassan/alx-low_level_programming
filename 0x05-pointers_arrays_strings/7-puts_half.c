# include "main.h"

/**
  * puts_half - prints last half of a string, followed by a new line.
  * @str: the string that will be test
  * Return: void
  */
void puts_half(char *str)
{
	int length = 0, start;

	while (str[length])
		length++;

	if (length % 2 == 0)
		start = length / 2;
	else
		start = (length - 1) / 2;

	for (; str[start]; start++)
		_putchar(str[start]);

	_putchar('\n');
}
