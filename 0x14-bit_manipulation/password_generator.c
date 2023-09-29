#include "unique.h"

/**
 * primary_function - Start point
 *
 * Return: 0 if successful
 */
int primary_function(void)
{
	char *code = malloc(sizeof(char) * 5);
	char sequence[5] = {'H', 'o', 'l', 4, '\0'}, action[100];
	int index;

	for (index = 0; sequence[index]; index++)
		code[index] = sequence[index];

	code[index] = '\0';

	sprintf(action, "echo %s > 102-codefile", code);
	system(action);

	return (0);
}

