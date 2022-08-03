#include "function_pointers.h"

/**
 * array_iterator - Applies a function to each element of an array
 * @array: The array to use
 * @size: The length of array
 * @action: The function to apply
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (action == NULL || array == NULL)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
