# include "main.h"

/**
  * print_last_digit - function that prints the last digit of a number.
  *
  * @n: the number to check
  *
  * Return: value of the last digit
  */
int print_last_digit(int n)
{
	int lastDigit;

	lastDigit = n % 10;
	if (lastDigit < 0)
	{
		lastDigit *= -1;
	}
	_putchar(lastDigit + '0');

	return (n % 10);
}
