#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int i, j, k, j1, j2, k1, k2;

	j = 1;
	k = 2;

	printf("%lu, %lu", j, k);

	for (i = 2; i < 91; i++)
	{
		unsigned long int next = j + k;

		printf(", %lu", next);
		j = k;
		k = next;
	}
	j1 = j / 1000000000;
	j2 = j % 1000000000;
	k1 = k / 1000000000;
	k2 = k % 1000000000;

	for (i = 92; i < 99; i++)
	{
		unsigned long int next1, next2;

		next1 = j1 + k1;
		next2 = j2 + k2;
		if (next2 > 1000000000)
		{
			next1 += 1;
			next2 = next2 % 1000000000;
		}
		printf(", %lu%lu", next1, next2);
		j1 = k1;
		j2 = k2;
		k1 = next1;
		k2 = next2;
	}

	printf("\n");
	return (0);
}

