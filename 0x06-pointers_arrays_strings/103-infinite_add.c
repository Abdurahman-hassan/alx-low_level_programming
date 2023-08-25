#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * infinite_add - Adds two numbers represented as strings.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 * Return: A pointer to the result string,
 * or 0 if result cannot be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	/* Find the lengths of the input strings n1 and n2 */
	int len1 = strlen(n1) - 1;
	int len2 = strlen(n2) - 1;

	/* Variables to keep track of sum and carry-over */
	int carry = 0, sum;

	/* Position for result string; -2 leaves space for null terminator */
	int pos = size_r - 2;

	/* Null-terminate the result string */
	r[size_r - 1] = '\0';

	/* Loop until we've processed each digit or until a carry is left */
	while (len1 >= 0 || len2 >= 0 || carry > 0)
	{
		/* If buffer space is exhausted, exit early */
		if (pos < 0)
			return (0);

		/* Start sum with any carry from previous step */
		sum = carry;

		/* If n1 still has characters left, add its current digit to sum */
		if (len1 >= 0)
			sum += n1[len1--] - '0';

		/* Add current digit from n2 to sum if any digits are left */
		if (len2 >= 0)
			sum += n2[len2--] - '0';

		/* Determine what will be carried over to the next iteration */
		carry = sum / 10;

		/* Store the last digit of sum to the buffer */
		r[pos--] = (sum % 10) + '0';
	}

	/* Return the starting position of the result in the buffer */
	return (r + pos + 1);
}
