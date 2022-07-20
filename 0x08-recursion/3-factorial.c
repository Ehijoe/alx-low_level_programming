#include "main.h"

/**
 * factorial - Computes the factorial of a given number
 * @n: Number to get the factorial of
 *
 * Return: -1 if n is less than 0 and the factorial of n otherwise
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	else
	{
		return (n * factorial(n - 1));
	}
}
