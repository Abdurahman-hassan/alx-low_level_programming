# include <stdio.h>
# include <stdlib.h>
# include "main.h"

/**
  * is_number - this function check that str is a number
  * @c: the string that will be checked
  * return 0 if false and 1 if true
  */
int is_number(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
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
	int i, j, sum = 0;

	/* First, check that all arguments are numbers */

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!is_number(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
	}

	/* Then, sum the arguments */

	for (i = 1; i < argc; i++)
	{
		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
