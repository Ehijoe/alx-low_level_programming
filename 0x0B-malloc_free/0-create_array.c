#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars and initializes it with a value
 * @size: Length of the array
 * @c: Character to initialize the array with
 *
 * Return: A pointer to the first byte in the array
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	if (size == 0)
	{
		return (NULL);
	}

	arr = malloc(size);
	if (arr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		arr[i] = c;
	}
	return (arr);
}
