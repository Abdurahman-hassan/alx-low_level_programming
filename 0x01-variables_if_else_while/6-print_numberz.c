# include <stdio.h>

/**
  * main - the Entry point
  *
  * Return: 0 Always (success)
  */
int main(void)
{
	unsigned int n = 0;

	while (n < 10)
	{
		/**
		  * conver int to char
		  * '0' is 48 in ASCII, so 2 + 48 == 50 that's equal to '2' in ASCI
		  */

		putchar(n + '0');
		n++;
	}
	putchar('\n');
	return (0);
}
