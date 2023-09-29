#ifndef _UNIQUE_H
#define _UNIQUE_H

#include "main.h"

/**
 * str_len - get length of string
 * @s: input string
 * Return: length of the string
 */
static inline int str_len(const char *s)
{
	int count;

	for (count = 0; s[count];)
		count++;

	return (count);
}

/**
 * binary_check - check for a valid binary string
 * @s: input string
 * Return: 1 if valid, 0 otherwise
 */
static inline int binary_check(const char *s)
{
	int index;

	for (index = 0; s[index]; index++)
		if (s[index] != '0' && s[index] != '1')
			return (0);

	return (1);
}

typedef unsigned int uint_alias;
typedef unsigned long int ulong_alias;

/**
 * index_check - verify if index is valid
 * @index: the index to check
 * Return: 1 if valid, 0 otherwise
 */
static inline int index_check(uint_alias index)
{
	uint_alias total_bits;

	total_bits = sizeof(ulong_alias) * 8;
	if (index > total_bits)
		return (0);

	return (1);
}
#endif
#ifndef NEW_CODE
#define NEW_CODE

/* Code generator structures */

/**
 * struct alpha_s - base structure
 * @c: character representation
 * @next: pointer to next item
 */
typedef struct alpha_s
{
	int c;
	struct alpha_s *next;
} alpha_x;

/**
 * struct alpha_g - secondary structure
 * @i: character group
 * @next: pointer to next group
 */
typedef struct alpha_g
{
	alpha_x i;
	struct alpha_g *next;
} alpha_grp;

#endif

