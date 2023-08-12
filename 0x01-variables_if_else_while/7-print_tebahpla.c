# include <stdio.h>

/**
  * main - the Entry point
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	char c = 'z';

	while (c >= 'a')
	{	putchar(c);
		c--;
	}
	putchar('\n');
	return (0);
}
