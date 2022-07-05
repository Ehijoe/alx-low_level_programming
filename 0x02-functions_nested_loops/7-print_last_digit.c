#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number
 * @n: The number whose last digit to print
 *
 * Return: The last digit of n
 */
int print_last_digit(int n)
{
	int last = n % 10;

	last = (last < 0) ? 10 + last : last;
	_putchar('0' + last);
	return (last);
}
