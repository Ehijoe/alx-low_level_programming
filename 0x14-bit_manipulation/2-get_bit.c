#include "main.h"

/**
 * get_bit - Gets the value of a bit at a particular index of an unsigned int
 * @n: The unsigned int to check
 * @index: The index of the desired bit
 *
 * Return: The bit at index or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	return ((int) ((n >> index) & 1U));
}
