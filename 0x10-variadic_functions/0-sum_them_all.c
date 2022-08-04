#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Add an unknown number of integers
 * @n: Number of ints to add
 *
 * Return: The sum of all the arguments but n
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list arg_list;

	va_start(arg_list, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg_list, int);
	}
	va_end(arg_list);
	return (sum);
}
