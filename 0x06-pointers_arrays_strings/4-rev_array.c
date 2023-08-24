# include "main.h"

/**
  * reverse_array - function that reverses
  * the content of an array of integers
  * @a: the pointer to array
  * @n: the number of element of array
  * Return: void
  */
void reverse_array(int *a, int n)
{
	int i, tmp ;
	int *start, *end;

	start = a;
	end = &a[n - 1];
	
	for (i = 0; i < n / 2; i++)
	{
		/* swap the elements */
		tmp = *start;
		*start = *end;
		*end = tmp;

		/** move the pointer */
		start++;
		end--;
	}
}
