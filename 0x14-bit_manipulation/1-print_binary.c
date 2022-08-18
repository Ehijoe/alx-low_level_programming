#include "main.h"

/**
 * print_binary - Print an unsigned int in binary form
 * @n: The unsigned int to print
 */
void print_binary(unsigned long int n)
{
	if (n >> 1)
	{
		print_binary(n >> 1U);
	}
	_putchar('0' + (n & 1U));
}
