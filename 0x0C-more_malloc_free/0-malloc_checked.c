#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory and exits on failure
 * @b: Size of memory to allocate
 *
 * Return: A pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *mem;

	mem = malloc(b);
	if (mem == NULL)
	{
		exit(98);
	}
	return (mem);
}
