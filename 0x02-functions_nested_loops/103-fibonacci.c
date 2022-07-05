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
	unsigned long a = 1, b = 2;
	unsigned long sum = 0;

	for (i = 0; a < 4000000; i++)
	{
		unsigned long tmp;

		tmp = a;
		a = b;
		b += tmp;

		if (a % 2 == 1)
		{
			sum += a;
		}
	}

	printf("%lu\n", sum);

	return (0);
}
