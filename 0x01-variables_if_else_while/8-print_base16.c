# include <stdio.h>

/**
  * main - the Entry point
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	unsigned int n = 0;

	while (n < 16)
	{
		if (n < 10)
			putchar(n + '0');
		else
			putchar(n - 10 + 'a');
		n++;
	}
	putchar('\n');
	return (0);
}
