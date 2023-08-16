# include "main.h"

/**
  * _islower - checks for lowercase character.
  *
  * @c the number of character in ASCI
  * Return: 1 if c is lowercase
  * And 0 in otherwise
  */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
