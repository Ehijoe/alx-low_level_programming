#include "variadic_functions.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * print_num - Prints a number in base 10
 * @n: Number to print
 */
void print_num(int n)
{
	printf("%d", n);
}

/**
 * print - Prints a string to the standard output
 * @s: The string to print
 */
void print(const char *s)
{
	if (s == NULL)
	{
		return;
	}
	printf("%s", s);
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

	if (n == 0)
	{
		printf("\n");
		return;
	}
	va_start(arg_list, n);
	for (i = 0; i < n; i++)
	{
		print_num(va_arg(arg_list, int));
		if (i == n - 1)
		{
			printf("\n");
		}
		else
		{
			print(separator);
		}
	}
	va_end(arg_list);
}
