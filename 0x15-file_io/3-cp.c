#include "main.h"

int initiate_file_open(char *src_file, char *dest_file);
int transfer_file_data(int source_fd, int target_fd);

/**
 * main - copies content from one file to another
 * @argc: argument count
 * @argv: argument values
 *
 * Return: 0 on success, error code on failure
 */
int main(int argc, char *argv[])
{
	int source_descriptor, dest_descriptor, closure_1, closure_2;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp source_file dest_file\n");
		exit(97);
	}

	source_descriptor = initiate_file_open(argv[1], argv[2]);
	dest_descriptor = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (transfer_file_data(source_descriptor, dest_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source %s\n", argv[1]);
		exit(98);
	}

	closure_1 = close(source_descriptor);
	closure_2 = close(dest_descriptor);
	if (closure_1 < 0 || closure_2 < 0)
	{
		if (closure_1 < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_descriptor);
		if (closure_2 < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_descriptor);
		exit(100);
	}
	return (0);
}

/**
 * initiate_file_open - Opens the source file for reading.
 * @src_file: The name of the source file to be opened.
 * @dest_file: The name of the destination file.
 * (Currently unused in the function but kept for consistency).
 * Description: This function attempts
 * to open the provided source file in read-only mode.
 * If it fails to open the source file,
 * it prints an error message and exits with status 98.
 * Return: File descriptor for the opened source file on success,
 * exits the program on failure.
 */
int initiate_file_open(char *src_file, char *dest_file)
{
	int file_desc = open(src_file, O_RDONLY);

	(void) dest_file;  /* Silence unused parameter warning */
	if (file_desc < 0)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read from %s\n", src_file);
		exit(98);
	}
	return (file_desc);
}
/**
 * transfer_file_data - Reads content from
 * the source file and writes to the target file.
 * @source_fd: File descriptor of the source file.
 * @target_fd: File descriptor of the destination/target file.
 * Description: This function reads
 * content from the source file into a buffer
 * and then writes from the buffer to the target file.
 * It reads and writes in chunks (defined by BUFSIZ)
 * until the entire file is copied.
 * If there's an error in reading
 * from the source or writing to the target,
 * it prints an appropriate error message.
 * Return: 0 on successful transfer,
 * -1 on any error during the transfer process.
 */
int transfer_file_data(int source_fd, int target_fd)
{
	char buffer[BUFSIZ];
	ssize_t read_data;

	while ((read_data = read(source_fd, buffer, BUFSIZ)) > 0)
	{
		if (write(target_fd, buffer, read_data) != read_data)
		{
			dprintf(STDERR_FILENO, "Error: Unable to write to target\n");
			close(source_fd);
			return (-1);
		}
	}
	return (read_data < 0 ? -1 : 0);
}
