#include "main.h"

/**
 * _isalpha - Checks if a character is a letter
 * @c: The character to be checked
 *
 * Return: 1 if c is a letter.
 * Otherwise 0 is returned.
 */
int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}

	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}

	return (0);
}
