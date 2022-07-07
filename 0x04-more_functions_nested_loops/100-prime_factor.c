#include <stdio.h>

/**
 * is_prime - Checks whether a number is prime
 * @n: Number to check
 *
 * Return: 1 if number is prime and 0 otherwise
 */
int is_prime(int n)
{
	int i = 3;

	if (n == 2)
	{
		return (1);
	}

	while (i * i < n)
	{
		if (n % i == 0)
			return (0);

		i += 2;
	}

	return (1);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int comp = 612852475143 / 4019;
	int i, max_prime = 1;

	for (i = 1; i < 1000000; i++)
	{
		if (comp % i == 0)
		{
			if (is_prime(i))
			{
				max_prime = i;
			}
		}
	}

	if (max_prime == 1)
	{
		printf("%ld\n", comp);
	}
	else
	{
		printf("%d\n", max_prime);
	}
	return (0);
}
