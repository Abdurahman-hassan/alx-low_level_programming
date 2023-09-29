#include "main.h"

/**
 * print_binary - Print the binary representation of a number.
 * @n: The number to be printed in binary.
 *
 * Description:
 * This function utilizes bitwise operations to print the
 * binary representation of a number. If n is zero, it prints
 * '0'. Otherwise, it shifts through each bit of the number, printing
 * '1' or '0' based on the bit's status.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;
	char flag = 0; /* To handle leading zeros */

	if (n == 0) /* Directly print 0 if the number is 0 */
	{
		_putchar('0');
		return;
	}

	mask = 1UL << ((sizeof(n) * 8) - 1); /* Set the mask to the highest bit */

	while (mask)
	{
		if (n & mask) /* Bit is set */
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag) /* Bit is unset but we've seen a set bit before */
		{
			_putchar('0');
		}
		mask >>= 1; /* Move the mask one bit to the right */
	}
}
