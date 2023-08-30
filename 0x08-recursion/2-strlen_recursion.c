# include "main.h"

/**
  * _strlen_recursion - function that returns the length of a string.
  * @s: the string that will calculate the length of it
  * Return: The number of chars, or 0 if faild
  */
int _strlen_recursion(char *s)
{
	int counter = 0;

	if (*s == '\0')
	{
		return (0);
	}

	counter++;

	return (counter + _strlen_recursion(s + 1));
}
