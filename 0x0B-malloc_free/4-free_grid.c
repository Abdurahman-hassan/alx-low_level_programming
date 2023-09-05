#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: the 2D grid to be freed
 * @height: the height of the grid
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
	int i;

	/* Loop through each row of the grid */
	for (i = 0; i < height; i++)
	{
		/* Free the memory allocated for the row */
		free(grid[i]);
	}

	/* Free the memory allocated for the grid itself */
	free(grid);
}
