#include "main.h"

/**
 * _strcat - Concatenate two null-terminated strings
 * @dest: A pointer to the starting string
 * @src: A pointer to the string to be concatenated to dest
 *
 * Return: A pointer the dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i++] = src[j++];
	}

	return (dest);
}
