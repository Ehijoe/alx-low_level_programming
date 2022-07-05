#include "main.h"
#include <stdio.h>

#define BASE 1000000000

/**
 * print2num - Print two numberss appended
 * @a: First number
 * @b: Second number
 */
void print2num(unsigned long a, unsigned long b)
{
	unsigned long n;
	int digits = 0, i;

	if (a == 0)
	{
		printf("%lu", b);
		return;
	}

	n = b;
	while (n /= 10)
		digits++;

	printf("%lu", a);

	digits = 9 - digits;
	for (i = 0; i < digits; i++)
	{
		printf("0");
	}

	printf("%lu", b);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long a1 = 1, a2 = 0, b1 = 2, b2 = 0;

	for (i = 0; i < 50; i++)
	{
		unsigned long tmp1, tmp2;

		print2num(a2, a1);
		tmp1 = a1;
		tmp2 = a2;
		a1 = b1;
		a2 = b2;

		b2 = b2 + tmp2 + ((b1 + tmp1) / BASE);
		b1 = (b1 + tmp1) % BASE;

		if (i == 49)
		{
			printf("\n");
		}
		else
		{
			printf(", ");
		}
	}

	return (0);
}
