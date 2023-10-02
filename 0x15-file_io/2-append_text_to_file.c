#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file.
 * @text_content: NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_res;
	size_t len = 0;

	/* Check if filename is NULL */
	if (!filename)
		return (-1);

	/* Open the file in append mode */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If text_content is NULL and file exists */
	if (!text_content)
	{
		close(fd);
		return (1);
	}

	/* Calculate the length of text_content */
	while (text_content[len])
		len++;

	/* Write text_content to the file */
	write_res = write(fd, text_content, len);

	/* Close the file */
	close(fd);

	/* Check if writing was successful */
	if (write_res == -1 || write_res != (int)len)
		return (-1);

	return (1);
}
