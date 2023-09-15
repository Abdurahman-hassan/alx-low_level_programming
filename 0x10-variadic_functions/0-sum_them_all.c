#include "variadic_functions.h"
#include <stdarg.h>

/**
  * sum_them_all - function that returns the sum of all its parameters.
  * @n: the size of list
  * Return: 0 if n == 0
  */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list args;

	va_start(args, n);

	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}

	va_end(args);

	return (sum);
}
