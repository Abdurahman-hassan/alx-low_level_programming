#include "main.h"

/**
 * helper - Recursively checks for square root.
 * @current: Current number to check.
 * @number: Original number to find the square root of.
 *
 * Return: Square root if exists, otherwise -1.
 */
int helper(int current, int number)
{
	/* Check if the square of current is equal to the number */
	if (current * current == number)
		return (current);

	/* If square of current surpasses number, return -1 */
	if (current * current > number)
		return (-1);

	/* Else, check for the next number */
	return (helper(current + 1, number));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The square root of n or -1 if n doesn't have a natural square root.
 */
int _sqrt_recursion(int n)
{
	/* Base cases */
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	/* Start checking from 2 */
	return (helper(2, n));
}
