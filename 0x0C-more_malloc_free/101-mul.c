#include "main.h"
#include <stdlib.h>
#include <ctype.h>

/* Function prototypes */
int is_only_digits(char *str);
void print_number(unsigned long int n);
void print_error(void);  /* Forward declaration of print_error */

/**
 * main - Entry point for the multiplication program.
 * @argc: The number of command-line arguments.
 * @argv: Array containing the program command-line arguments.
 *
 * Return: 0 on success, or exit with a status of 98 on error.
 */
int main(int argc, char *argv[])
{
	unsigned long int num1, num2, product;

	/* Check if the number of arguments is correct */
	if (argc != 3)
	{
		print_error();
		exit(98);
	}

	/* Check if num1 and num2 contain only digits */
	if (!is_only_digits(argv[1]) || !is_only_digits(argv[2]))
	{
		print_error();
		exit(98);
	}

	/* Convert the string arguments to unsigned long integers and multiply */
	num1 = strtoul(argv[1], NULL, 10);
	num2 = strtoul(argv[2], NULL, 10);
	product = num1 * num2;

	/* Print the multiplication result */
	print_number(product);
	_putchar('\n');
	return (0);
}

/**
 * is_only_digits - Verify if a string contains only digit characters.
 * @str: The string to check.
 *
 * Return: 1 if the string contains only digits, otherwise 0.
 */
int is_only_digits(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * print_number - Print an unsigned long integer to stdout.
 * @n: The number to be printed.
 *
 * Description: This function recursively divides the number by 10 to
 *              determine each digit, which is then printed with _putchar.
 */
void print_number(unsigned long int n)
{
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * print_error - Print an error message to stdout.
 *
 * Description: This function outputs "Error" followed by a newline.
 */
void print_error(void)
{
	char *error = "Error";

	while (*error)
	{
		_putchar(*error);
		error++;
	}
	_putchar('\n');
}
