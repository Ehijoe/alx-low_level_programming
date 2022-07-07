#include "main.h"

/**
 * _print_number_helper - Prints a number to stdout
 * @n: The number to print
 *
 * Description: A helper function that prints a number without a newline.
 * To be used in print_number.
 */
void _print_number_helper(int n)
{
	if (n < 0)
	{
		print_number(n * -1);
		return;
	}

	if (n > 10)
	{
		print_number(n / 10);
	}

	_putchar('0' + (n % 10));
}

/**
 * _print_number_helper - Prints a number to stdout
 * @n: The number to print
 */
void print_number(int n)
{
	_print_number_helper(n);
	_putchar('\n');
}
