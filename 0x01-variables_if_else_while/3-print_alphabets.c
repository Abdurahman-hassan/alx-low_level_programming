# include <stdio.h>

/**
  * main - the Entry point
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	int i = 0;
	char c;

	while (i < 52)
	{	c = (i < 26) ? 'a' + i : 'A' + i - 26;
		putchar(c);
		i++;
	}
	putchar('\n');
	return (0);
}
