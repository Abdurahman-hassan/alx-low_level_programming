#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: Pointer to the number.
 * @index: The index, starting from 0 of the bit to set.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	/* If the index is larger than the max bits */
	/* in an unsigned long int, return -1 */
	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	/* Shift 1 to the left by 'index' positions to create a mask */
	mask = 1 << index;

	/* Use OR operation to set the bit at that index */
	*n = *n | mask;

	return (1);
}
