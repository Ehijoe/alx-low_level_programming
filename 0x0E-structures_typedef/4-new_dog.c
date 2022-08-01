#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - Gets the length of a string
 * @s: String to get the length of
 *
 * Return: Length of s
 */
unsigned int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcpy - Copies a string to another location in memory
 * @dest: Location to copy to
 * @src: Location to copy from
 */
void _strcpy(char *dest, char *src)
{
	int i;

	if (src == NULL)
	{
		return;
	}
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

/**
 * new_dog - Create a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Name of the dog's owner
 *
 * Return: A pointer to the created dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
	{
		return (NULL);
	}
	dog->age = age;
	if (name == NULL)
	{
		dog->name = NULL;
	}
	else
	{
		dog->name = malloc(_strlen(name) + 1);
		if (dog->name == NULL)
		{
			free(dog);
			return (NULL);
		}
	}
	if (owner == NULL)
	{
		dog->owner = NULL;
	}
	else
	{
		dog->owner = malloc(_strlen(owner) + 1);
		if (dog->owner == NULL)
		{
			free(dog->name);
			free(dog);
			return (NULL);
		}
	}

	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);

	return (dog);
}
