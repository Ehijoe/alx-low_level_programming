#include "main.h"

/**
 * _strncpy - Copy at most n characters from src to dest
 * @dest: A pointer to the starting string
 * @src: A pointer to the string to be copied to dest
 * @n: Number of characters to copy
 *
 * Return: A pointer to dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (src[j] != '\0' && j < n)
	{
		dest[i++] = src[j++];
	}

	if (src[j] == '\0')
	{
		while (i < n)
		{
			dest[i++] = '\0';
		}
	}

	return (dest);
}
