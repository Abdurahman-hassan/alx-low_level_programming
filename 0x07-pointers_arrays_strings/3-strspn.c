# include "main.h"

/**
  * _strspn - function that gets the length of a prefix substring.
  * @s: the main string
  * @accept: the checker string
  * Return: number of bytes in the initial segment of s
  * which consist only of bytes from accept
  */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	for (; *s != '\0'; s++)
	{
		char *a;

		for (a = accept; *a != '\0'; a++)
		{

			if (*s == *a)
			{
				break;
			}
		}

		if (*a == '\0')
		{
			return (count);
		}

		count++;
	}


	return (count);
}
