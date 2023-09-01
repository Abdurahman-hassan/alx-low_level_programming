# include "main.h"

/**
  * _abs - function that computes the absolute value of an integer
  *
  * @n: the number to check
  *
  * Return: The number in positive value
  */
int _abs(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}

	return (n);
}
