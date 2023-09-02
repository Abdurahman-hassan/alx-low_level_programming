# include <stdio.h>
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
	if (argc > 0)
	{
		printf("%s\n",argv[0]);
	}
	return (0);
}
