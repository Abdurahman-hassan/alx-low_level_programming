#include "main.h"

/**
 * create_file - Creates a file with specified content.
 * @filename: Name of the file to create.
 * @text_content: NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t write_res;
	int length = 0;

	/* If filename is NULL, return -1 */
	if (!filename)
		return (-1);

	/* Open or create file with permissions rw-------*/
	/* and truncate if it already exists */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* If text_content is not NULL, write its content to the file */
	if (text_content)
	{
		while (text_content[length])
			length++;

		write_res = write(fd, text_content, length);
		if (write_res == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
