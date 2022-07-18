#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Print the sum of the diagonals of a square matrix
 * @a: Matrix to sum
 * @size: Size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i = 0, sum_maj = 0, sum_min = 0;

	for (i = 0; i < size; i++)
	{
		sum_maj += a[i * (size + 1)];
	}

	for (i = 1; i <= size; i++)
	{
		sum_min += a[i * (size - 1)];
	}

	printf("%d, %d\n", sum_maj, sum_min);
}
