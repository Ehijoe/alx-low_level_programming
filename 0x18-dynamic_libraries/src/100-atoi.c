#include "main.h"

/**
 * _atoi - Converts a string number to an int
 * @s: String to convert to an int
 *
 * Return: Returns the integer value of s
 */
int _atio(char *s)
{
	int sign = 1, value = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}

	while (*s != '\0')
	{
		value += *s - '0';
		s++;
	}

	return (value * sign);
}
