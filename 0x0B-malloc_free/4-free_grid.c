#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a grid allocated by alloc_grid
 * @grid: The grid to free
 * @height: The number of rows in the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
	{
		return;
	}

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
