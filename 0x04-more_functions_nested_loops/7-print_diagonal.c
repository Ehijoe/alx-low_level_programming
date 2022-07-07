#include "main.h"

/**
 * print_diagonal - Print a diagonal line made of \
 * @n: Number of \ to print
 */

void print_diagonal(int n)
{
	if (n > 0)
	{
		int i;

		print_diagonal(n - 1);
		for (i = 0; i < n - 1; i++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
	}
	else
	{
		_putchar('\n');
	}
}
