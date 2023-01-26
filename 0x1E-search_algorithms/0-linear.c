#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - Search an unsorted array for a value
 * @array: Pointer to the array
 * @size: Size of the array
 * @value: The value to search for
 *
 * Return: The index of the first occurrence.
 *         -1 if the value is not found or array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
	unsigned int i;

	if (array == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
