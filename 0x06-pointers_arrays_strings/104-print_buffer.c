#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints a buffer content.
 * @b: The buffer.
 * @size: The size of the buffer.
 */
void print_buffer(char *b, int size)
{
	int i, j;

	/* Check for a non-positive size */
	if (size <= 0)
	{
		printf("\n");
		return;
	}
	/* Iterate through the buffer 10 bytes at a time */
	for (i = 0; i < size; i += 10)
	{
		/* Print the address offset in hexadecimal */
		printf("%08x: ", i);

		/* Print the hexadecimal representation of each byte */
		for (j = 0; j < 10; j++)
		{
			/* If we're still within the buffer size */
			if (i + j < size)
				printf("%02x", b[i + j]);
			else
				printf("  ");
			/* Print spaces if outside buffer size */
			/* Separate pairs of bytes with a space */
			if (j % 2)
				printf(" ");
		}

		/* Print the actual buffer content, if it's printable */
		for (j = 0; j < 10 && i + j < size; j++)
		{
			/* Check for printable ASCII values (from 32 to 126) */
			if (b[i + j] >= 32 && b[i + j] <= 126)
				putchar(b[i + j]);
			else
				putchar('.');
			/* Non-printable chars are represented by a dot */
		}
		printf("\n");
	}
}
