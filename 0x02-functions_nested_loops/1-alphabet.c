#include "main.h"

/**
 * print_alphabet - Print the alphabet in lowercase followed by a newline
 */
void print_alphabet(void)
{
	char l;

	for (l = 'a'; l <= 'z'; l++)
	{
		_putchar(l);
	}
	_putchar('\n');
}
