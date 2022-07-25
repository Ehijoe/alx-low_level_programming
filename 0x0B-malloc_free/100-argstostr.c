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
 * argstostr - Concatenates the arguments of a program
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: Pointer to concatenated string
 */
char *argstostr(int ac, char **av)
{
	int i, length, count;
	char *result;

	if (ac < 1 || av == NULL)
	{
		return (NULL);
	}

	length = 0;
	for (i = 0; i < ac; i++)
	{
		length += _strlen(av[i]) + 1;
	}
	result = malloc(length + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	count = 0;
	for (i = 0; i < ac; i++)
	{
		int j, arglen = _strlen(av[i]);

		for (j = 0; j < arglen; j++)
		{
			result[count++] = av[i][j];
		}
		result[count++] = '\n';
	}
	result[count] = '\0';

	return (result);
}
