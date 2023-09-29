#include "main.h"

/**
 * get_bit - Get the value of a bit at a given index.
 * @n: The number.
 * @index: The index, starting from 0 of the bit to get.
 * Description: If an error occurs, return -1. Otherwise, return the bit value.
 * Return: The value of the bit at the index or -1 if an error occurs.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	/* If the index is larger than the max bits */
	/* in an unsigned long int, return -1 */
	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	/* Shift 1 to the left by 'index' positions to create a mask */
	n = n & (1 << index);

	/* Right shift to get the bit value */
	return (n >> index);
}
