#include "main.h"

/**
 * check_prime - Checks if a number is prime
 * @n: Number to check
 * @a: Test value to check divisibility
 *
 * Return: 1 if n is prime and 0 otherwise.
 */
int check_prime(int n, int a)
{
	if (n == a)
	{
		return (1);
	}
	else if (n % a == 0)
	{
		return (0);
	}
	else
	{
		return (check_prime(n, a + 1));
	}
}

/**
 * is_prime_number - Checks if a number is prime
 * @n: Number to check
 *
 * Return: 1 if n is prime and 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n < 2)
	{
		return (0);
	}
	return (check_prime(n, 2));
}
