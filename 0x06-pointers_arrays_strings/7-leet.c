# include "main.h"

/**
  * leet - function that encodes a string into 1337.
  * Letters a and A should be replaced by 4
  * Letters e and E should be replaced by 3
  * Letters o and O should be replaced by 0
  * Letters t and T should be replaced by 7
  * Letters l and L should be replaced by 1
  * @c: is the char that will convert
  * Return: pointer to conversion array
  */
char *leet(char *c)
{
	int i = 0, j = 0;
	char letters[] = {'a', 'e', 'o', 't', 'l'};
	char numbers[] = {'4', '3', '0', '7', '1'};

	while (c[i])
	{
		for (j = 0; j < 5; j++)
		{
			if (c[i] == letters[j] || c[i] == letters[j] - 32)
			{
				c[i] = numbers[j];
			}
		}

		i++;
	}

	return (c);
}
