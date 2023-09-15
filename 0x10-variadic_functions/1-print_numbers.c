#include "variadic_functions.h"

/**
  * print_numbers - function that prints numbers, followed by a new line.
  * @separator: the string to be printed between numbers
  * @n: the number of integers passed to the function
  * If separator is NULL, don’t print it
  * Return: void
  */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		if (i < n - 1 && separator)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
