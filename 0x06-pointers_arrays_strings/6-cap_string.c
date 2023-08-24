# include "main.h"

/**
  * is_separator - checks if the char is seperator
  * @c: the char to check
  * Return: 1 if it's a seperator otherwise 0
  */
int is_separator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int i;

	for (i = 0; separators[i]; i++)
	{
		if (c == separators[i])
			return (1);
	}

	return (0);
}


/**
  * cap_string - function that capitalizes all words of a string.
  * Separators of words: space, tabulation,
  * new line , ; . ! ? " ( ) { }
  * @ch: the array of words that will be capitalize
  * Return: cap words
  */
char *cap_string(char *ch)
{
	int i = 0;

	if (ch[0] >= 'a' && ch[0] <= 'z')
		ch[0] -= 32;

	while (ch[i])
	{
		if (is_separator(ch[i]) && ch[i + 1] >= 'a' && ch[i + 1] <= 'z')
			ch[i + 1] -= 32;
		i++;
	}
	return (ch);
}
