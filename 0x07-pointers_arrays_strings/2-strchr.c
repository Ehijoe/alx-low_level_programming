#include "main.h"
#include <stddef.h>

/**
 * _strchr - Finds the first occurence of a character in a string
 * @s: String to search
 * @c: Character to find
 *
 * Return: A pointer to the first occurrence of c.
 *         NULL if c is not found.
 */
char *_strchr(char *s, char c)
{
	char *ptr = s;

	while (*ptr != c)
	{
		if (*ptr == '\0')
		{
			return (NULL);
		}
		ptr++;
	}

	return (ptr);
}
