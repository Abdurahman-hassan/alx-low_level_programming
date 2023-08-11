# include <stdio.h>

/**
  * main - the Entry point
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{	putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
