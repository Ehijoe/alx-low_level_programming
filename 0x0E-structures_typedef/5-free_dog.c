#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Free the memory occupied by a dog
 * @d: A pointer to the dog
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}
	if (d->name != NULL)
	{
		free(d->name);
	}
	if (d->owner != NULL)
	{
		free(d->owner);
	}
	free(d);
}
