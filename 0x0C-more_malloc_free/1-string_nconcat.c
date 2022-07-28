#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Find the number of characters in a null-terminated string
 * @s: String whose characters to count
 *
 * Return: The number of characters in s. 0 if s is NULL
 */
int _strlen(char *s)
{
	int length = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * string_nconcat - Concatenate two strings
 * @s1: Starting string
 * @s2: Ending string
 * @n: Number of chars in s2 to concatenate
 *
 * Return: The concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i;
	unsigned int size, size1, size2;
	char *result;

	size1 = _strlen(s1);
	size2 = _strlen(s2);
	size2 = (size2 > n) ? n : size2;
	size = size1 + size2;

	result = malloc(size + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size1; i++)
	{
		result[i] = s1[i];
	}
	for (i = 0; i < size2; i++)
	{
		result[i + size1] = s2[i];
	}
	result[size] = '\0';

	return (result);
}
