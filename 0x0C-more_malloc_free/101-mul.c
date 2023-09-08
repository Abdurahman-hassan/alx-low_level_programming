#include <stdlib.h>
#include "main.h"

/**
 * is_digit - Check if a string consists only of digits.
 * @s: The string to evaluate.
 * Return: 1 if the string consists only of digits, 0 otherwise.
 * Description: This function loops through each character of the string
 * and checks if it's a digit or not.
 */
int is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - Compute the length of a string.
 * @s: The string to measure.
 *
 * Return: The length of the string.
 *
 * Description: Loops through the string till the null terminator is found
 * and returns the length.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * errors - Print an error message and exit the program.
 *
 * Description: This function prints "Error" and exits the program
 * with a status code of 98.
 */
void errors(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * multiply - Multiply two strings representing numbers.
 * @s1: First number as a string.
 * @s2: Second number as a string.
 * @len1: Length of s1.
 * @len2: Length of s2.
 *
 * Return: A pointer to an array holding the result.
 *
 * Description: This function multiplies two numbers represented as strings.
 * It utilizes the classical multiplication method to compute the result.
 */
int *multiply(char *s1, char *s2, int len1, int len2)
{
	int i, j, carry, *result;
	int len = len1 + len2;

	result = malloc(sizeof(int) * len);
	if (!result)
		errors();

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			int sum;

			sum = (s1[i] - '0') * (s2[j] - '0') + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i + j + 1] += carry;
	}

	return (result);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 * Return: 0 if successful, or 1 if an error occurs.
 * Description: The main function first checks the input arguments.
 * If they're valid, it calls the multiply function and then
 * displays the result.
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, i, *result, a = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();

	s1 = argv[1];
	s2 = argv[2];
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	result = multiply(s1, s2, len1, len2);
	len = len1 + len2;

	for (i = 0; i < len; i++)
	{
		if (result[i] != 0 || a != 0)
		{
			_putchar(result[i] + '0');
			a = 1;
		}
	}

	if (a == 0)
		_putchar('0');

	_putchar('\n');

	free(result);
	return (0);
}
