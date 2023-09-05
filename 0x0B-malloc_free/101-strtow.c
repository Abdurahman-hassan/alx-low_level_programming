#include "main.h"
#include <stdlib.h>

/**
 * word_count - Counts the number of words in a string.
 * @str: The string to be evaluated.
 * Return: The number of words found in the string.
 */
int word_count(char *str)
{
	int count = 0, i = 0;

	/** Loop through the entire string */
	while (str[i])
	{
		while (str[i] == ' ') /** Skip spaces */
			i++;
		/** If character is not a space, increment word count */
		if (str[i] != ' ' && str[i] != '\0')
			count++;
		/** Skip characters of the current word */
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	return (count);
}
/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 * Return: Pointer to an array of strings where each entry is a word.
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, l, wordsCount, wordLen;

	if (!str || !*str)
		return (NULL); /** Handle null or empty string */
	wordsCount = word_count(str); /** Get total word count */
	if (wordsCount == 0)
		return (NULL);
	/** Allocate memory for array of words */
	words = malloc(sizeof(char *) * (wordsCount + 1));
	if (!words)
		return (NULL);
	/** Loop to extract each word */
	for (j = 0; j < wordsCount; j++)
	{
		while (str[i] == ' ') /** Skip spaces */
			i++;
		wordLen = 0;
		/** Calculate the current word length */
		while (str[i + wordLen] != ' ' && str[i + wordLen])
			wordLen++;
		/** Allocate memory for the current word */
		words[j] = malloc(sizeof(char) * (wordLen + 1));
		if (!words[j])
		{
			/** Free allocated memory in case of failure */
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		/** Copy the word into the allocated memory */
		for (l = 0; l < wordLen; l++)
			words[j][l] = str[i + l];
		words[j][l] = '\0';
		i += wordLen; /** Move to the next word */
	}
	words[j] = NULL; /** Mark the end of the array of strings */
	return (words);
}
