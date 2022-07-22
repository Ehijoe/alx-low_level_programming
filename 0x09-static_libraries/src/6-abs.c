#include "main.h"

/**
 * _abs - Computes the absolute value of a number
 * @n: The number whose absolute value to compute
 *
 * Return: The absolute value of n
 */
int _abs(int n)
{
	int val = n;

	if (val < 0)
	{
		val = -1 * val;
	}
	return (val);
}
