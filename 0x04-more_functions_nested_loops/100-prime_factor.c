#include <stdio.h>
#include <math.h>

/**
 * main - Finds and prints the largest prime factor of the number 612852475143.
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n = 612852475143;
	long int maxPrime = -1; /* Initially set to -1 for validation. */
	long int i;

	/* Removing all the even factors of 2. */
	while (n % 2 == 0)
	{
		maxPrime = 2;
		n /= 2;
	}

	/* Finding odd prime factors. */
	for (i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			maxPrime = i;
			n /= i;
		}
	}

	/* If n is a prime number greater than 2. */
	if (n > 2)
		maxPrime = n;

	printf("%ld\n", maxPrime);

	return (0);
}

