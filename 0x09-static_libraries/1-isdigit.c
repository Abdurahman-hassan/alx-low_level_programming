# include "main.h"

/**
  * _isdigit - This function check for digit
  *
  * @c: is the digit to be checked
  *
  * Return: 1 if c is isdigit
  * 0 othervise
  */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}

	return (0);
}
