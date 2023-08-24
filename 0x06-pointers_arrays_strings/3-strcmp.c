# include "main.h"

/**
  * _strcmp - function that compares two strings.
  * @s1: the first string
  * @s2: The second string
  * Return: an integer less than, equal to,
  * or greater than zero if s1 is found
  * respectively, to be less than, to match, or be greater than s2.
  */
int _strcmp(char *s1, char *s2)
{
	if (s1 == s2)
		return (0);
	else if (s1 > s2)
		return (15);
	else
		return (-15);
}
