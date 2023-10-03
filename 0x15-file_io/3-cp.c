#include "main.h"

#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: argument list
 * Return: 0 on success, or one of the error codes on failure
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd, bytes_read, close_src_status, close_dest_status;
	char buffer[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	source_fd = open(argv[1], O_RDONLY);
	if (source_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((bytes_read = read(source_fd, buffer, BUFSIZ)) > 0)
	{
		if (dest_fd < 0 || write(dest_fd, buffer, bytes_read) != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(source_fd);
			exit(99);
		}
	}

	if (bytes_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	close_src_status = close(source_fd);
	close_dest_status = close(dest_fd);

	if (close_src_status < 0 || close_dest_status < 0)
	{
		if (close_src_status < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		if (close_dest_status < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		exit(100);
	}

	return (0);
}
