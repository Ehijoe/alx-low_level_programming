#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
 * _calloc - Allocates memory for `nmemb` elements of size `size`
 * @nmemb: Number of elements
 * @size: Size of each element
 *
 * Return: A pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned long int mem_size = nmemb * size;
	char *memory = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	if (mem_size > UINT_MAX)
	{
		return (NULL);
	}
	memory = malloc(mem_size);
	if (memory == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < mem_size; i++)
	{
		memory[i] = 0;
	}
	return (memory);
}
