#include "main.h"

/**
 * print_line - Print a line made of _
 * @n: Number of _ to print
 */

void print_line(int n)
{
	if (n > 0)
	{
		_putchar('_');
		print_line(n - 1);
	}
	else
	{
		_putchar('\n');
	}
}
