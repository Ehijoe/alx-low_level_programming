#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Change the size of allocated memory
 * @ptr: A pointer to the allocated memory
 * @old_size: Size of memory previously allocated
 * @new_size: Size of memory to be allocated
 *
 * Return: A pointer to the new block of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *old = ptr;
	char *new;

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	new = malloc(new_size);
	for (i = 0; i < new_size && i < old_size; i++)
	{
		new[i] = old[i];
	}
	free(old);
	return ((void *) new);
}
