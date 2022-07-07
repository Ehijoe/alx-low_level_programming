#include "main.h"
#include <stdlib.h>

/**
 * print_number - Prints a number to stdout
 * @n: The number to print
 *
 * Description: A helper function that prints a number without a newline.
 * To be used in print_number.
 */
void print_number(int n)
{
	unsigned int n1 = n;

	if (n < 0)
	{
		n1 = abs(n);
		_putchar('-');
	}

	if (n1 / 10)
	{
		print_number(n1 / 10);
	}

	_putchar('0' + (n1 % 10));
}
