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
	/* i will use argv */

	int i, counter = 0;
	
	(void)argv;

	if (argc > 0)
	{
		for (i = 0; i < argc; i++)
		{
			counter++;
		}
		printf("%d\n",counter - 1);
	}
	return (0);
}
