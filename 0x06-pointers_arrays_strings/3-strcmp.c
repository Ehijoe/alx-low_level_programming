#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: 0 if they are the same
 *         negative if s1 is smaller
 *         and postitive otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}

	return (0);
}
