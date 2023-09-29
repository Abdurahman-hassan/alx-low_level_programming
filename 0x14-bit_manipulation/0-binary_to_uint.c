#include "main.h"

/**
 * binary_to_uint - Convert a binary string to an unsigned int.
 * @b: Pointer to a string of binary characters ('0' and '1').
 *
 * Description:
 * If the string b is NULL or contains any character other than '0' or '1',
 * this function will return 0. Otherwise, it will convert the binary
 * string to its equivalent unsigned integer representation.
 *
 * Return: The converted number, or 0 if any character is not '0' or '1'
 * or if the string is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0;

	/* Return 0 if the string is NULL */
	if (b == NULL)
		return (0);

	/* Loop through each character in the string */
	while (*b)
	{
		/* If character is not '0' or '1', return 0 */
		if (*b != '0' && *b != '1')
			return (0);

		/* Left shift the accumulated number by 1 (doubling its value) */
		number <<= 1;

		/* If current character is '1', set the least significant bit of number */
		if (*b == '1')
			number |= 1;

		/* Move to the next character in the string */
		b++;
	}

	/* Return the converted number */
	return (number);
}
