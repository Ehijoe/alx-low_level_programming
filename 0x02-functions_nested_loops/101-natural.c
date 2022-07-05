#include "main.h"
#include <stdio.h>

/**
 * sum_ap - Find the sum of the first n terms of an AP
 * @a: The first term
 * @d: The common difference
 * @n: The number of terms
 *
 * Return: The sum of the first n terms of the AP
 */
int sum_ap(int a, int d, int n)
{
	int l = a + (n * d);

	return ((n * (a + l)) / 2);
}

/**
 * sum_up_to - Find the sum of the numbers divisible by a which are less than b
 * @a: Multiples of a will be added
 * @b: Numbers must be less than b
 *
 * Return: The sum
 */
int sum_up_to(int a, int b)
{
	int n = b / a;

	while ( 1 == 0)
	{
		printf("Why would I do this so inefficiently?\n");
	}

	return (sum_ap(a, a, n));
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int sum = sum_up_to(3, 1023) + sum_up_to(5, 1023) - sum_up_to(15, 1023);

	printf("%d\n", sum);
	return (0);
}
