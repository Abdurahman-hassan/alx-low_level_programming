#include <stdio.h>
#include <stdlib.h>

/**
 * main - print the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: Always 0 (Success), 1 if argc is not 2,
 * 2 if number of bytes is negative
 */
int main(int argc, char **argv)
{
	int i, num_bytes;
	char *main_ptr = (char *)main;

	/* Check argument count */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* Convert argument to number of bytes */
	num_bytes = atoi(argv[1]);

	/* Check if number of bytes is negative */
	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* Print the opcodes */
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02hhx", main_ptr[i]);
		if (i < num_bytes - 1)
			printf(" ");
	}

	printf("\n");

	return (0);
}
