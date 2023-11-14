# include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On succcess 1.
 * On error, -1 is returned, and errno is set apprapriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _islower - checks for lowercase character.
 *
 * @c: the number of character in ASCI
 * Return: 1 if c is lowercase
 * And 0 in otherwise
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

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

/**
 * _abs - function that computes the absolute value of an integer
 *
 * @n: the number to check
 *
 * Return: The number in positive value
 */
int _abs(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}

	return (n);
}

/**
 * _isupper - This function checks the for the upper chars
 *
 * @c: The char to check
 *
 * Return: 1 if c is uppercase
 * 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}

	return (0);
}

/**
 * _isdigit - This function check for digit
 *
 * @c: is the digit to be checked
 *
 * Return: 1 if c is isdigit
 * 0 othervise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}

	return (0);
}

/**
 * _strlen - Compute the length of a string.
 * @s: The string to measure.
 *
 * Return: The length of the string.
 *
 * Description: Loops through the string till the null terminator is found
 * and returns the length.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * _puts - function that prints a string, followed by a new line, to stdout
 * @str: the string that will be print
 * Return: void
 */
void _puts(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}

/**
 * _strcpy - function that copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest.
 * @dest: this will copied into
 * @src: the string that will be copy
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	/* the last char should be \0 */
	dest[i] = '\0';

	return (dest);
}


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

/**
 * _strcat - function that concatenates two strings
 * @dest: the final concating string
 * @src: the string that will concat with dest
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int dest_length = 0, i;

	while (dest[dest_length])
	{
		dest_length++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_length + i] = src[i];
	}

	dest[dest_length + i] = '\0';

	return (dest);
}

/**
 * _strncat - function that concatenates two strings
 * @dest: the final concating string
 * @src: the string that will concat with dest
 * @n: size of bytes
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_length = 0, i;

	while (dest[dest_length])
	{
		dest_length++;
	}

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_length + i] = src[i];

	if (n <= 0)
		dest[dest_length + i] = '\0';

	return (dest);
}

/**
 * _strncpy -  function that copies a string
 * @dest: The string that will copy to
 * @src: the string that will copy from
 * @n: the number of byts
 * Return: string that have src with dest content
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

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
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _memset - this function fills memory with a constant byte.
 * The _memset() function fills the first n bytes of the memory
 * area pointed to by s with the constant byte b
 * @s: array that will point to
 * @b: the data will be fill into @s
 * @n: the number of bytes that will be fill
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

/**
 * _memcpy - function that copies memory area.
 * The _memcpy() function copies n bytes from memory area
 * src to memory area dest
 * @dest: the char that will copy to
 * @src: the char that will copy from
 * @n: number of bytes
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}


/**
 * _strchr - function that locates a character in a string.
 * @s: the main string that will look into
 * @c: the main char that will look for
 * Return: a pointer to the first occurrence of the character c
 * in the string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}
	/* If c is the null terminator, return a pointer to it */
	if (c == '\0')
		return (s);

	/* If the loop completes without finding the character, return NULL */
	return (NULL);
}

/**
 * _strspn - function that gets the length of a prefix substring.
 * The _strspn() function calculates the length (in bytes) of the initial
 * segment of s which consists entirely of bytes in accept
 * @s: the main string
 * @accept: the string that will look for the first match string
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;

	for (i = 0; s[i] != '\0'; i++) {
		int found = 0;  /* Flag to check if s[i] exists in accept*/

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				count++;
				break;  /* No need to continue the inner loop once a match is found*/
			}
		}

		if (!found)
			break;  /* Exit the loop if the character is not found in accept*/
	}

	return (count);
}

/**
 * _strpbrk - function that searches a string for any of a set of bytes.
 * The _strpbrk() function locates the first occurrence
 * in the string s of any of the bytes in the string accept
 * @s: the main string
 * @accept: the string that will look for the first match string
 * Return: a pointer to the byte in s that matches
 * one of the bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	for (; *s != '\0'; s++)
	{
		char *a;

		for (a = accept; *a != '\0'; a++)
		{
			if (*s == *a)
				break;
		}
		/* If we didn't reach the end of 'accept', then a match was found */
		if (*a != '\0')
			return (s);
	}

	return (NULL);
}

/**
 * _strstr - function that locates a substring.
 * The _strstr() function finds the first occurrence of the substring
 * needle in the string haystack.
 * The terminating null bytes (\0) are not compared.
 * @haystack: the main string to be searched
 * @needle: the substring to search for
 * Return: a pointer to the beginning of the located substring,
 * or '\0' if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	/** Declare and initialize loop counters */
	int i, j;

	/** If needle is an empty string, return haystack. */
	if (!needle[0])
		return (haystack);

	/** Loop through each character in haystack */
	for (i = 0; haystack[i]; i++)
	{
		/* Check if the characters */
		/* from the current position match needle */
		/* continue if the condition is valid break if not valid */

		for (j = 0; needle[j] && (haystack[i + j] == needle[j]); j++)
			;

		/* If we've found the entire needle */
		/* return a pointer to its location in haystack */
		/* \0 is fasle not false is true if true return the adress */
		if (!needle[j])
			return (&haystack[i]);
	}

	/** If no match is found, return '\0' */
	return (NULL);
}
