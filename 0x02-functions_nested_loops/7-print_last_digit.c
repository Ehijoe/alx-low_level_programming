#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number
 * @n: The number whose last digit to print
 *
 * Return: The last digit of n
 */
int print_last_digit(int n)
{
	int last = n;

	last = (last < 0) ? -1 * last : last;
	last = last % 10;
	_putchar('0' + last);
	return (last);
}
