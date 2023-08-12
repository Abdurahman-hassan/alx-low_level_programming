# include <stdio.h>

/**
  * main - the Entry point
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	unsigned int first, second;

	for (first = 0; first <= 99  ; first++)
	{
		for (second = first + 1; second <= 99; second++)
		{
			putchar((first / 10) + '0');
			putchar((first % 10) + '0');
			putchar(' ');

			putchar ((second / 10) + '0');
			putchar ((second % 10) + '0');

			if (first != 98 || second != 99)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
