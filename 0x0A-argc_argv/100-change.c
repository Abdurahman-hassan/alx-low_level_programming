#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_valid_integer - Check if a string represents a valid integer.
 * @input: String to check.
 * Return: 1 if the string represents a valid integer, 0 otherwise.
 */
int is_valid_integer(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (!isdigit(input[i]))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * calculate_coins - Calculate the minimum number of coins needed to
 * make change for a given amount of cents.
 * @cents: Amount of cents.
 * Return: The minimum number of coins needed.
 */
int calculate_coins(int cents)
{
	int quarters, dimes, nickels, pennies, total;

	quarters = cents / 25;
	cents %= 25;
	dimes = cents / 10;
	cents %= 10;
	nickels = cents / 5;
	cents %= 5;
	pennies = cents;

	total = quarters + dimes + nickels + pennies;

	return (total);
}

/**
 * main - The entry point of the program.
 * @argc: The number of arguments passed to the program,
 *        including the program's name.
 * @argv: An array of strings representing the arguments passed
 *        to the program. The first argument is the program's name.
 *
 * Return: 0 on success, or a non-zero value on error.
 */
int main(int argc, char *argv[])
{
	int cents, total;
	char *input;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	input = argv[1];

	if (!is_valid_integer(input))
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(input);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	total = calculate_coins(cents);

	printf("%d\n", total);

	return (0);
}
