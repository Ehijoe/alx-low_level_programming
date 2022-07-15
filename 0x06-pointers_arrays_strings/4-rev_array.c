#include "main.h"

/**
 * reverse_array - Reverses the elements of an array
 * @a: The array to reverse
 * @n: The number of elements in the array
 */
void reverse_array(int *a, int n)
{
	int i, tmp, half;

	half = n / 2;
	for (i = 0; i < half; i++)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - i - 1] = tmp;
	}
}
