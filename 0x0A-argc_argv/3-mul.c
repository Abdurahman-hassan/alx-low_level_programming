# include <stdio.h>
# include <stdlib.h>
# include "main.h"

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
	int i, mul = 1;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		mul *=  atoi(argv[i]);
	}

	printf("%d\n", mul);

	return (0);
}
