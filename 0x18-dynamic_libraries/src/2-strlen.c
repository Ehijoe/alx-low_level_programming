#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string whose length to count
 *
 * Return: The length of s
 */
int _strlen(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen(s + 1));
}
