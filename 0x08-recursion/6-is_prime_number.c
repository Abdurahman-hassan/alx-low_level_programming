#include "main.h"

/**
 * actual_prime - Recursively checks if a number is prime.
 * @n: The number to check.
 * @i: Current divisor.
 * Return: 1 if n is prime, 0 otherwise.
 */
int actual_prime(int n, int i)
{
	/** Base case: If i is 1, then n is prime as no divisors were found. */
	if (i == 1)
	{
		return (1);
	}

	/** If n is divisible by i, then n is not prime. */
	if (n % i == 0)
	{
		return (0);
	}

	/** Continue to check with the next smaller divisor. */
	return (actual_prime(n, i - 1));
}

/**
 * is_prime_number - Determines if a number is prime.
 * @n: The number to check.
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	/** Basic case: 0 and 1 are not prime. */
	if (n < 2)
	{
		return (0);
	}

	/** Start the recursive check with n - 1 as the initial divisor. */
	return (actual_prime(n, n - 1));
}
