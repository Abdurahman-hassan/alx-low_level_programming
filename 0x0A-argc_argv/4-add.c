# include <stdio.h>
# include <stdlib.h>
# include "main.h"

/**
 * is_digit - Check if a character is a digit (0 through 9) or a minus sign.
 * @ch: Character to check.
 * Return: 1 if ch is a digit or minus sign, return 0 otherwise.
 */
int is_digit(int ch)
{
	/* Check if character is a digit or a minus sign */
	if ((ch >= '0' && ch <= '9') || ch == '-')
		return (1);
	else
		return (0);
}

/**
 * main - The entry point of the program.
 * @arg_count: The number of arguments passed to the program,
 *        including the program's name.
 * @arg_values: An array of strings representing the arguments passed
 *        to the program. The first argument is the program's name.
 *
 * Return: 0 on success, or a non-zero value on error.
 */
int main(int arg_count, char *arg_values[])
{
	int idx, jdx, result = 0;
	char *curr_arg = NULL;

	/* If no numbers are passed, print 0 and return */
	if (arg_count < 2)
	{
		printf("0\n");
		return (0);
	}

	/* Check each argument */
	for (idx = 1; idx < arg_count; idx++)
	{
		curr_arg = arg_values[idx];
		for (jdx = 0; curr_arg[jdx] != '\0'; jdx++)
		{
			/* If any character is not a digit */
			/* or minus sign, print error and return 1 */
			if (is_digit(curr_arg[jdx]) != 1)
			{
				printf("Error\n");
				return (1);
			}
		}
		/* Convert argument to integer and add to result */
		result += atoi(arg_values[idx]);
	}

	/* Print the result */
	printf("%d\n", result);

	return (0);
}
