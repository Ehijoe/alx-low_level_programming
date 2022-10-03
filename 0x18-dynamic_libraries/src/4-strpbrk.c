#include "main.h"
#include <stddef.h>

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
    char *tmp = ptr;
    int contains = 0;

	while (*tmp != '\0')
	{
		if (*tmp == *ptr)
		{
			contains = 1;
		}
		tmp++;
	}

	while (!contains)
	{
		if (*ptr == '\0')
		{
			return (NULL);
		}
		ptr++;

        contains = 0;
        tmp = ptr;

        while (*tmp != '\0')
        {
            if (*tmp == *ptr)
            {
                contains = 1;
            }
            tmp++;
        }
	}

	return (ptr);
}
