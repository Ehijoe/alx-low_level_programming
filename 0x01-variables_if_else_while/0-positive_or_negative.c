#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char *sign;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n < 0)
	{
		sign = "negative";
	}
	else if (n > 0)
	{
		sign = "positive";
	}
	else
	{
		sign = "zero";
	}

	printf("%d is %s\n", n, sign);

	return (0);
}
