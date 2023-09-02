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
	int i = 0;

	if (argc > 0)
	{
		while (argv[0][i])
		{
			_putchar(argv[0][i]);
			i++;
		}
		_putchar('\n');
	}

	return (0);
}
