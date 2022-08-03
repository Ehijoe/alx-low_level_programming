#include "function_pointers.h"

/**
 * int_index - Finds the first element that satisfies a condition
 * @array: The array to search
 * @size: The length of the array
 * @cmp: A function that check the condition
 *
 * Return: The index of the first match found. -1 if none is found.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
	{
		return (-1);
	}
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		{
			return (i);
		}
	}
	return (-1);
}
