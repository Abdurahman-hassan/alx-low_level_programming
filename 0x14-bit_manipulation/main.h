#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/**
 * union endian_test - A union for testing endianness
 * @i: An unsigned int member
 * @c: A char array member of size of unsigned int
 *
 * Description: This union is used to test the endianness of the system.
 * By setting the 'i' member to 1 and checking the first byte of 'c',
 * we can determine if the system is little-endian or big-endian.
 */
union endian_test
{
	unsigned int i;
	char c[sizeof(unsigned int)];
} union_test;


unsigned int binary_to_uint(const char *b);
int _putchar(char c);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int get_endianness(void);

#endif
