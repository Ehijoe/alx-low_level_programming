#include "main.h"
#include <stddef.h>

/**
 * contains - Check if a character is in a string
 * @s: String to check
 * @c: Character to look for
 *
 * Return: 1 if c is found and 0 otherwise.
 */
int contains(char *s, char c)
{
	char *ptr = s;

	while (*ptr != '\0')
	{
		if (*ptr == c)
		{
			return (1);
		}
		ptr++;
	}

	return (0);
}

/**
 * _strpbrk - Finds the first occurence of a character in a string
 * @s: String to search
 * @accept: String of characters to find
 *
 * Return: A pointer to the first occurrence of a character in accept.
 *         NULL if c is not found.
 */
char *_strpbrk(char *s, char *accept)
{
	char *ptr = s;

	while (!contains(accept, *ptr))
	{
		if (*ptr == '\0')
		{
			return (NULL);
		}
		ptr++;
	}

	return (ptr);
}
