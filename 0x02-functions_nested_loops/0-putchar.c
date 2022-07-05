#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print("_putchar");

	return (0);
}


/**
 * print - Print a string to standard output followed by a newline
 * @string: The string to print
 *
 * Return: The number of characters printed to standard output.
 */
int print(char *string)
{
	int printed = 0;

	while (string[printed])
	{
		_putchar(string[printed++]);
	}
	_putchar('\n');
	printed++;

	return (printed);
}
