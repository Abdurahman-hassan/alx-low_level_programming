#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
	int cents, quarters, dimes, nickels, pennies, total;
	char *input;
	int i;

	/* Check if the number of arguments is correct */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	input = argv[1];

	/* Check if the input is a valid integer */
	for (i = 0; input[i] != '\0'; i++)
	{
		if (!isdigit(input[i]))
		{
			printf("Error\n");
			return (1);
		}
	}

	/* Convert the argument to an integer */
	cents = atoi(input);

	/* If the number of cents is negative, print 0 and return */
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/* Calculate the number of coins needed */
	quarters = cents / 25;
	cents %= 25;
	dimes = cents / 10;
	cents %= 10;
	nickels = cents / 5;
	cents %= 5;
	pennies = cents;

	/* The total number of coins is the sum of all the coins calculated */
	total = quarters + dimes + nickels + pennies;

	printf("%d\n", total);

	return (0);
}
