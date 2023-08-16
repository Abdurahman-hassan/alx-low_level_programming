#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers
 * starting with 1 and 2.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int a = 1, b = 2, next;
	int count;

	for (count = 1; count <= 50; count++)
	{
		printf("%ld", a);

		/* Add comma and space for all numbers except the last one */
		if (count < 50)
			printf(", ");
		else
			printf("\n");

		next = a + b;  /* Calculate the next Fibonacci number */
		a = b;        /* Move a to the next number */
		b = next;     /* Move b to the next number */
	}

	return (0);
}

