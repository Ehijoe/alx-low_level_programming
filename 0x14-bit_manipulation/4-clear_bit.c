#include "main.h"

/**
 * clear_bit - Clears a bit at a particular index of an unsigned int
 * @n: A pointer to the unsigned int to change
 * @index: The index of the bit to clear
 *
 * Return: 1 on success and -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (n == NULL)
		return (-1);
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask = ~(1U << index);
	*n = *n & mask;
	return (1);
}
