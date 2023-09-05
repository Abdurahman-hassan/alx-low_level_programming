#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The argument count.
 * @av: The argument values.
 * Description: This function concatenates all the arguments of your program.
 * Each argument should be followed by a '\n' in the new string.
 *
 * Return: A pointer to the new string, or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, len = 0;
	char *s;

	/* Return NULL if ac is zero or av is NULL */
	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the total length of the resulting string */
	for (i = 0; i < ac; i++)
		for (j = 0; av[i][j]; j++)
			len++;

	/* Allocate memory for the concatenated string */
	s = malloc(sizeof(char) * (len + ac + 1));
	if (s == NULL)
		return (NULL);

	k = 0;
	/* Iterate through each argument and copy into the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			s[k++] = av[i][j];
		s[k++] = '\n';
	}
	s[k] = '\0';

	return (s);
}
