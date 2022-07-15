#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @s: The string to encode
 *
 * Return: A pointer to the string
 */
char *leet(char *s)
{
	char lower[] = "aeotl";
	char upper[] = "AEOTL";
	char replace[] = "43071";
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (s[i] == upper[j] || s[i] == lower[j])
			{
				s[i] = replace[j];
			}
		}
	}

	return (s);
}
