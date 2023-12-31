# include "main.h"

/**
  * puts2 - function that prints every other character
  * of a string, starting with the first character, followed by a new line.
  * @str: the string that we will test it
  * Return void
  */
void puts2(char *str)
{
	int length = 0, i;

	while (str[length])
		length++;

	for (i = 0; i < length; i += 2)
		_putchar(str[i]);

	_putchar('\n');
}
