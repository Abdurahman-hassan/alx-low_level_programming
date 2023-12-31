# include "main.h"

/**
  * factorial - function that returns the factorial of a given number.
  * @n: the number to use in factorial
  * Return: the factorial of given number,
  * -1 if n < 0 or 1 if n == 0
  */
int factorial(int n)
{
	if (n < 0)
	{
		/* ndicate an error */
		return (-1);
	}

	if (n == 0)
	{
		return (1);
	}

	return (n * factorial(n - 1));


}
