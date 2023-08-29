#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: 2D array representing the matrix.
 * @size: Size of the matrix (since it's a square matrix, it's size x size).
 */
void print_diagsums(int a[][8], int size)
{
	/* Initialize sums for the two diagonals */
	int sum1 = 0;
	int sum2 = 0;
	int i;

	/* Iterate through the matrix to calculate the sums */
	for (i = 0; i < size; i++)
	{
		sum1 += a[i][i];              /* Main diagonal */
		sum2 += a[i][size - 1 - i];   /* Other diagonal */
	}

	/* Print the diagonal sums */
	printf("%d, %d\n", sum1, sum2);
}
