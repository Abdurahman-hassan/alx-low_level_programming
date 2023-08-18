#include <stdio.h>

/**
  * find_next_prime_factor - This function find_next_prime_factor
  * @num: the number
  * @start: The starter number
  * Return: divisor
  */
long find_next_prime_factor(long num, long start)
{
	long divisor = start;

	while (divisor <= num)
	{
		if (num % divisor == 0)
		{
			return (divisor);
		}
		divisor++;
	}
	return (-1);
}

/**
  * print_prime_factors - This is print_prime_factors
  *
  * @num: this is the number
  * Return: The number
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
			{
				printf(" and ");
			}
			else
			{
				printf(", ");
			}
		}
		printf("%ld", divisor);
		printedFactors++;
		num /= divisor;
	}
	printf(".\n");
}

/**
  * main - This is the entry point
  *
  * Return: 0 if success
  */
int main(void)
{
	long num = 612852475143;

	print_prime_factors(num);
	return (0);
}

