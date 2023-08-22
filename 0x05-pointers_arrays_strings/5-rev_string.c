# include "main.h"

/**
  * rev_string - function that reverses the original string
  * @s: is the string that will be reversed
  * Return: void
  */
void rev_string(char *s)
{
	int length = 0, i, tmp;

	while (s[length])
		length++;

	for (i = 0; i < length / 2; i++)
	{
		/* the first chars */
		tmp = s[i];

		/* the chars from the end */
		s[i] = s[length - 1 - i];

		/* put the first char that stors */
		/* in tmp to the last char */
		s[length - 1 - i] = tmp;

		/*"olleh" -> "o with h" -> hlleo*/
		/* "hlleo" -> "l with e" -> hello*/
		/* the l will stay as it becase we / 2 the only half*/
	}
}
