#include "main.h"
#include <stdlib.h>

/**
 * array_range - Create an array of values from min to max
 * @min: Lowest value in the array
 * @max: Highest value in the array
 *
 * Return: A pointer to the generated array
 */
int *array_range(int min, int max)
{
	int diff = max - min;
	int *array;
	int i;

	if (diff < 0)
	{
		return (NULL);
	}
	array = malloc(sizeof(int) * (diff + 1));
	if (array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= diff; i++)
	{
		array[i] = min + i;
	}
	return (array);
}
