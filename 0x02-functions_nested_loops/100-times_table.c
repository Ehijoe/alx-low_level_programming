#include "main.h"

/**
 * print_times_table - Print the times table from 0 to n
 * @n: Limit to stop the times table
 */
void print_times_table(int n)
{
	int i, j;

	if (n > 15 || n < 0)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (j == 0)
			{
				_putchar('0');
			}
			else
			{
				int val = i * j;

				_putchar(',');
				_putchar(' ');
				_putchar((val >= 100) ? (val / 100) + '0' : ' ');
				val %= 100;
				_putchar((val >= 10) ? (val / 10) + '0' : ((i * j) >= 100) ? '0' : ' ');
				_putchar('0' + (val % 10));
			}
		}
		_putchar('\n');
	}
}
