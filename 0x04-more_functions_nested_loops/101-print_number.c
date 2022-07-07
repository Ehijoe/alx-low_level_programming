#include "main.h"

/**
 * print_number - Prints a number to stdout
 * @n: The number to print
 *
 * Description: A helper function that prints a number without a newline.
 * To be used in print_number.
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		print_number(n * -1);
		return;
	}

	if (n >= 10)
	{
		print_number(n / 10);
	}

	_putchar('0' + (n % 10));
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_number(98);
    _putchar('\n');
    print_number(402);
    _putchar('\n');
    print_number(1024);
    _putchar('\n');
    print_number(0);
    _putchar('\n');
    print_number(-98);
    _putchar('\n');
    return (0);
}
