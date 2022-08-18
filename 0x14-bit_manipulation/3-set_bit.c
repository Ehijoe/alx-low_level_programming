#include "main.h"

/**
 * set_bit - Sets the bit of an unsigned integer at a particular index to 1
 * @n: A pointer to the unsigned integer to change
 * @index: The index of the bit to set
 *
 * Return: 1 on success and -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (n == NULL)
		return (-1);
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask = 1U << index;
	*n = *n | mask;
	return (1);
}
