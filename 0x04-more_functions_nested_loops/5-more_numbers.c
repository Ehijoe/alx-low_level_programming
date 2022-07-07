#include "main.h"

/**
 * more_numbers - Print numbers from 0 to 14
 */
void more_numbers(void)
{
	int i;

	for (i = 0; i <= 14; i++)
	{
		if (i >= 10)
		{
			_putchar('0', i / 10);
		}
		_putchar('0' + (i % 10));
	}
	_putchar('\n');
}
