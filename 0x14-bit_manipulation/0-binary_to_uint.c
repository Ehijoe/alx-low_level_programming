#include "main.h"

/**
 * binary_to_uint - Convert a string of 0's and 1's to an unsigned integer
 * @b: The string to convert
 *
 * Return: The unsigned int or 0 if an invalid string is passed
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n, i;

	n = 0;
	if (b == NULL)
	{
		return (0);
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		n <<= 1;
		if (b[i] == '1')
		{
			n++;
		}
		else if (b[i] != '0')
		{
			return (0);
		}
	}
}
