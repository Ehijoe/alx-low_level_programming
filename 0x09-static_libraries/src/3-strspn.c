#include "main.h"

/**
 * _strspn - Gets the length of prefix of s with characters from accept
 * @s: String to search
 * @accept: String of characters to accept
 *
 * Return: Number of accepted characters at beginning of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		char accepted = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				accepted = 1;
				break;
			}
		}

		if (!accepted)
		{
			break;
		}
	}

	return (i);
}
