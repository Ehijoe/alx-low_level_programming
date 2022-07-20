#include "main.h"

/**
 * sqrt_check - Checks if a number is a square root
 * @n: Number whose square root to find
 * @a: Number to try as a square root
 *
 * Return: The square root of n or -1 if it isn't natural
 */
int sqrt_check(int n, int a)
{
	int square = a * a;

	if (square > n)
	{
		return (-1);
	}
	else if (square == n)
	{
		return (a);
	}
	else
	{
		return (sqrt_check(n, a + 1));
	}
}

/**
 * _sqrt_recursion - Finds the square root of a number
 * @n: Number whose square root to find
 *
 * Return: -1 if n has no natural square root.
 *         Otherwise returns the square root of n.
 */
int _sqrt_recursion(int n)
{
	return (sqrt_check(n, 0));
}
