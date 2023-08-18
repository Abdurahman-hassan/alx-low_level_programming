#include <stdio.h>

/**
 * find_next_prime_factor - Find smallest prime factor of a number.
 * @num: The number to find the prime factor for.
 * @start: Starting divisor for the search.
 *
 * Return: The smallest prime factor or -1 if none found.
 */
long find_next_prime_factor(long num, long start)
{
	long divisor = start;

	while (divisor <= num)
	{
		if (num % divisor == 0)
			return (divisor);
		divisor++;
	}
	return (-1);
}

/**
 * print_prime_factors - Print prime factors of a number.
 * @num: The number to print prime factors for.
 */
void print_prime_factors(long num)
{
	long divisor = 2;
	int factorCount = 0;
	int printedFactors = 0;
	long original_num = num;

	while (num != 1)
	{
		divisor = find_next_prime_factor(num, divisor);
		factorCount++;
		num /= divisor;
	}

	divisor = 2;
	num = original_num;
	printf("The prime factors of %ld are ", num);

	while (num != 1)
	{
		divisor = find_next_prime_factor(num, divisor);
		if (printedFactors > 0)
		{
			if (printedFactors + 1 == factorCount)
				printf(", and ");
			else
				printf(", ");
		}
		printf("%ld", divisor);
		printedFactors++;
		num /= divisor;
	}
	printf(".\n");
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	long num = 612852475143;

	print_prime_factors(num);
	return (0);
}

