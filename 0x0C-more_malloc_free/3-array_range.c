#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers.
 * @min: The starting value of the array.
 * @max: The maximum value of the array.
 *
 * Return: Pointer to the newly created array or NULL on failure.
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, size;

	/* If min > max, return NULL */
	if (min > max)
	{
		return (NULL);
	}

	size = max - min + 1;

	/* Allocate memory for the array */
	arr = malloc(size * sizeof(int));
	if (!arr)
	{
		return (NULL);
	}

	/* Populate the array with values from min to max */
	for (i = 0; min <= max; min++, i++)
	{
		arr[i] = min;
	}

	return (arr);
}
