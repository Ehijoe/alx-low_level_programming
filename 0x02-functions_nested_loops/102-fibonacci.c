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
	unsigned long int a = 1, b = 2;

	for (i = 0; i < 50; i++)
	{
		int tmp;

		printf("%lu", a);
		tmp = a;
		a = b;
		b += tmp;

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
