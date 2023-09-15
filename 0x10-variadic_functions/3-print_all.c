#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *s, *separator = "";

	va_start(args, format);
	while (format && format[i])
	{
		printf("%s", separator);
		switch (format[i])
		{
		case 'c':
			printf("%c", va_arg(args, int));
			break;
		case 'i':
			printf("%d", va_arg(args, int));
			break;
		case 'f':
			printf("%f", va_arg(args, double));
			break;
		case 's':
			s = va_arg(args, char *);
			if (!s)
			{
				printf("(nil)");
				break;
			}
			printf("%s", s);
			break;
		default:
			i++; /* if it's an unknown format */
			separator = "";
			continue; /* reset separator and continue */
		}

		separator = ", "; /* Update separator for next iterations */
		i++;
	}

	printf("\n");
	va_end(args);
}
