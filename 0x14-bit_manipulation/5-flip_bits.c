#include "main.h"

/**
 * flip_bits - Gets the number of bits that should be flipped to make n = m
 * @n: The first number to compare
 * @m: The second number to compare
 *
 * Return: The number of bits in which n and m differ
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count, diff;

	diff = n ^ m;
	count = 0;
	while (diff)
	{
		count += diff & 1;
		diff >>= 1;
	}

	return (count);
}
