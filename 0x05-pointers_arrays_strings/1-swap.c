# include "main.h"

/**
  * swap_int - this function swaps the values of two integers.
  * @a: is the first int
  * @b: is the seconed int
  * Return: void
  */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
