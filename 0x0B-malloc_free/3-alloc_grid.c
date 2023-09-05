#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2D array of integers
 * @width: the width of the 2D array
 * @height: the height of the 2D array
 *
 * Return: pointer to the 2D array (Success) or NULL (Error)
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	/* Check if width or height is less than or equal to 0 */
	if (width <= 0 || height <= 0)
		return (NULL);

	/* Allocate memory for the height (rows) of the grid */
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		/* Allocate memory for the width (columns) of each row */
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			/* Free any rows already allocated in case of failure */
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}

		/* Initialize all elements of the row to 0 */
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}

	return (grid);
}
