#include "main.h"

/**
 * get_endianness - Checks the system's endianness.
 *
 * Description: This function determines if the system is using little-endian
 * or big-endian format to store multi-byte data types. It utilizes a union
 * comprising of an unsigned int and a char array. By setting the int to 1,
 * the first byte of the char array can be checked to determine the endianness.
 *
 * Return: 1 if the system is little-endian, 0 if big-endian.
 */
int get_endianness(void)
{
	/* Set the int part of the union to 1 */
	union_test.i = 1;

	/* If the first byte of the char array is 1, it's little-endian.*/
	/* Otherwise, it's big-endian. */
	return ((union_test.c[0] == 1) ? 1 : 0);
}
