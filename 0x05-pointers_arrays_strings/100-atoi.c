#include "main.h"

/**
 * _atoi - Convert a string to an integer considering the signs.
 * @s: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
	int result = 0;  /* Store the resulting integer */
	int sign = 1;    /* To handle the signs - and + */
	int started = 0; /* To check if number conversion has started */

	while (*s)
	{
		/* If current char is a minus sign, toggle the sign value */
		if (*s == '-')
			sign = -sign;

		/* If the current char is a number */
		if (*s >= '0' && *s <= '9')
		{
			started = 1;  /* Set started to true */
			result = result * 10 + (*s - '0') * sign;

			/* If the next char is not a number, break out of the loop */
			if (!(*(s + 1) >= '0' && *(s + 1) <= '9'))
				break;
		}
		else if (started)
		{
			/* If number conversion had started and current char is not a number */
			break;
		}
		s++;
	}
	return (result);
}
