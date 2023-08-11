# include <stdio.h>

/**
  * main - the Entry point
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	unsigned int n;

	while (n < 10)
	{
		printf("%u", n);
		n++;
	}
	putchar('\n');
	return (0);
}
