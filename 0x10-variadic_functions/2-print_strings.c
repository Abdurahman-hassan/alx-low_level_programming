#include "variadic_functions.h"

/**
  * print_strings - function that prints strings, followed by a new line.
  * @separator: the string to be printed between numbers
  * @n: the number of string passed to the function
  * If separator is NULL, don’t print it
  * If one of the string is NULL, print (nil) insteaD
  * Return: void
  */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		/* if str is NULL*/
		if (!str)
			printf("nil");
		printf("%s", str);

		if (i < n - 1 && separator)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
