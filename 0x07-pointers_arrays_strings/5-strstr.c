#include "main.h"
#include <stddef.h>

/**
 * _strstr - Finds a substring of a string
 * @haystack: String to search
 * @needle: Substring to find
 *
 * Return: A pointer to the first occurrence of the substring in the string.
 *         NULL if no substring is found.
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;
	int found = 0;
	char *substring = haystack;

	while (haystack[i] != '\0')
	{
		if (needle[j] == '\0')
		{
			return (substring);
		}
		if (haystack[i] == needle[j])
		{
			if (!found)
			{
				found = 1;
				substring = haystack + i;
			}
			j++;
		}
		else
		{
			found = 0;
			j = 0;
		}
		i++;
	}

	if (haystack[i] == needle[j])
	{
		return (substring);
	}

	return (NULL);
}
