#include "main.h"

/**
 * copy_file - Copies content from one file to another.
 * @file_from: File descriptor of the source file.
 * @file_to: File descriptor of the destination file.
 * @argv: Argument vector for error printing.
 * Return: 1 on success, -1 on failure.
 */
int copy_file(int file_from, int file_to, char *argv[])
{
	char buffer[BUFFER_SIZE];
	int read_res, write_res;

	while ((read_res = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_res = write(file_to, buffer, read_res);
		if (write_res != read_res)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			return (-1);
		}
	}

	if (read_res == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (-1);
	}

	return (1);
}

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(file_from);
		exit(99);
	}

	if (copy_file(file_from, file_to, argv) == -1)
		exit(99);

	if (close(file_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	if (close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}

	return (0);
}
