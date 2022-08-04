#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print - Prints a string to the standard output
 * @s: The string to print
 */
void print(char *s)
{
	int i;

	if (s == NULL)
	{
		print("(nil)");
		return;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
}

/**
 * print_strings - Prints strings seperated by a string
 * @separator: The string that separates the strings
 * @n: The number of strings to print
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list arg_list;
	unsigned int i;

	va_start(arg_list, n);
	for (i = 0; i < n; i++)
	{
		print(va_arg(arg_list, char *));
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
