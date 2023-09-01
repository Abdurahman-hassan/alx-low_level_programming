# include "main.h"

/**
  * _isalpha - function that checks for alphabetic character
  *
  * @c: is the alph that represent in ASCI code
  *
  * Return: 1 if c is a letter, lowercase or uppercase
  * 0 if otherwise
  */
int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
