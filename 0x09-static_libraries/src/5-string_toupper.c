#include "main.h"

/**
 * string_toupper - Converts lowercase letters in a string to uppercase
 * @s: String to convert
 *
 * Return: A pointer to the string.
 */
char *string_toupper(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] += 'A' - 'a';
		}
	}

	return (s);
}
