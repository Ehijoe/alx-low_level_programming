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
	int n, last;
	char *size;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	last = n % 10;

	if (last > 5)
	{
		size = "greater than 5";
	}
	else if (last == 0)
	{
		size = "0";
	}
	else
	{
		size = "less than 6 and not 0";
	}

	printf("Last digit of %d is %d and is %s\n", n, last, size);

	return (0);
}
