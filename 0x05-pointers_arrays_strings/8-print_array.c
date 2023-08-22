# include <stdio.h>
# include "main.h"

/**
  * print_array -  function that prints n elements of an array 
  * of integers, followed by a new line.
  * Numbers must be separated by comma, followed by a space
  * @a: is the array
  * @n: size of array
  * Return: void
  */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i < n - 1)
		{
			printf("%d, ",a[i]);
		}
		else
			printf("%d",a[i]);
	}

	printf("\n");
}
