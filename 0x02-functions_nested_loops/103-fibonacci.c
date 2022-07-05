#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned int a = 1, b = 2;
	unsigned long sum = 0;

	for (i = 0; a < 4000000; i++)
	{
		int tmp;

		tmp = a;
		a = b;
		b += tmp;

		if (i % 2 == 1)
		{
			sum += a;
		}
	}

	printf("%lu\n", sum);

	return (0);
}
