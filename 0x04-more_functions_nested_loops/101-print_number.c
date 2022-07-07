#include "main.h"

/**
 * print_number - Prints a number to stdout
 * @n: The number to print
 *
 * Description: A helper function that prints a number without a newline.
 * To be used in print_number.
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		print_number(n * -1);
		return;
	}

	if (n >= 10)
	{
		print_number(n / 10);
	}

	_putchar('0' + (n % 10));
}
