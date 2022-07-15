#include "main.h"

/**
 * _strncat - Concatenate two null-terminated strings
 * @dest: A pointer to the starting string
 * @src: A pointer to the string to be concatenated to dest
 * @n: Number of characters to append
 *
 * Return: A pointer the dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0' && j < n)
	{
		dest[i++] = src[j++];
	}

	dest[i] = '\0';

	return (dest);
}
