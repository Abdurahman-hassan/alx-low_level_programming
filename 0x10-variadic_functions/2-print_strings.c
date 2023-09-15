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
	char *str;

	va_list list;

	va_start(list, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(list, char *);
		if (!str)
			str = "(nil)";

		/* Print separator for all but the first string */
		if (i > 0 && separator)
			printf("%s", separator);

		printf("%s", str);
	}

	printf("\n");

	va_end(list);
}
