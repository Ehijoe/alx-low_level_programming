#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_num - Prints a number in base 10
 * @n: Number to print
 */
void print_num(int n)
{
	unsigned int a;

	if (n < 0)
	{
		a = -n;
		print_num(a);
		return;
	}
	if (n > 10)
	{
		print_num(n / 10);
	}
	_putchar('0' + (n % 10));
}

/**
 * print - Prints a string to the standard output
 * @s: The string to print
 */
void print(char *s)
{
	int i;

	if (s == NULL)
	{
		return;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
}

/**
 * print_numbers - Prints numbers seperated by a string
 * @separator: The string that separates the numbers
 * @n: The number of numbers to print
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list arg_list;
	unsigned int i;

	va_start(arg_list, n);
	for (i = 0; i < n; i++)
	{
		print_num(va_arg(arg_list, int));
		if (i == n - 1)
		{
			_putchar('\n');
		}
		else
		{
			print(separator);
		}
	}
	va_end(arg_list);
}
