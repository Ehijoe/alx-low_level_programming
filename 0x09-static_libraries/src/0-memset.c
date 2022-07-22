#include "main.h"

/**
 * _memset - Set the first n bytes of s to b
 * @s: String to modify
 * @b: Fill character
 * @n: Number of characters to set
 *
 * Return: A pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
