#include "main.h"

/**
 * _memcpy - Copy n bytes from src to dest
 * @dest: Destination to copy bytes
 * @src: Source of the bytes
 * @n: Number of bytes to copy
 *
 * Return: A pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
