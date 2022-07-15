#include "main.h"

/**
 * rot13 - Encodes a string using rot13
 * @s: The string to encode
 *
 * Return: A pointer to the string
 */
char *rot13(char *s)
{
	char alpha[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char cipher[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYXABCDEFGHIJKLM";
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (s[i] == alpha[j])
			{
				s[i] = cipher[j];
			}
		}
	}

	return (s);
}
