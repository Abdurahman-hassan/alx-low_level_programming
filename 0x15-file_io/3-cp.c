#include "main.h"

/**
 * copy_content - Copies content from one file to another.
 * @source_fd: File descriptor for the source file.
 * @dest_fd: File descriptor for the destination file.
 * Return: 0 on success, -1 on failure.
 */
int copy_content(int source_fd, int dest_fd)
{
	char buffer[BUFSIZ];
	ssize_t bytes_read;

	while ((bytes_read = read(source_fd, buffer, BUFSIZ)) > 0)
	{
		if (write(dest_fd, buffer, bytes_read) != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			return (-1);
		}
	}

	if (bytes_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		return (-1);
	}

	return (0);
}

/**
 * handle_files - Handles opening and closing of files.
 * @src: Name of the source file.
 * @dest: Name of the destination file.
 * Return: 0 on success, or the appropriate error code.
 */
int handle_files(char *src, char *dest)
{
	int source_fd, dest_fd, close_status;

	source_fd = open(src, O_RDONLY);
	if (source_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		return (98);
	}

	dest_fd = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (dest_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't create/write to file %s\n", dest);
		close(source_fd);  /* Close the source file before returning */
		return (99);
	}

	if (copy_content(source_fd, dest_fd) == -1)
	{
		close(source_fd);  /* Ensure the source file descriptor is closed */
		close(dest_fd);    /* Also close the destination file descriptor*/
		return (99);
	}

	close_status = close(source_fd);
	if (close_status < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		return (100);
	}

	close_status = close(dest_fd);
	if (close_status < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		return (100);
	}

	return (0);
}

/**
 * main - Entry point of the program.
 * Copies the content of a file to another file.
 * @argc: number of arguments passed to the program.
 * @argv: argument list.
 * Return: 0 on success, or one of the error codes on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	int status = handle_files(argv[1], argv[2]);

	if (status != 0)
		exit(status);

	return (0);
}
