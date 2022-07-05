#include "main.h"

/**
 * times_table - Print the times table from 0 to 9
 */
void times_table(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
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
				_putchar((val >= 10) ? (val / 10) + '0' : ' ');
				_putchar('0' + (val % 10));
			}
		}
		_putchar('\n');
	}
}
