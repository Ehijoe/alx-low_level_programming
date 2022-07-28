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
	unsigned long long int mem_size = nmemb * size;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	if (mem_size > UINT_MAX)
	{
		return (NULL);
	}
	return (malloc(mem_size));
}
