#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Creates a duplicate of a string
 * @str: String to duplicate
 *
 * Return: A pointer to the new string, or NULL if errors occur
 */
char *_strdup(char *str)
{
	char *dup;
	int length, i;

	if (str == NULL)
	{
		return (NULL);
	}

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	dup = malloc(length + 1);
	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';

	return (dup);
}
