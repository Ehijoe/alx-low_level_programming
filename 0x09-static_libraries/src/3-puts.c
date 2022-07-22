#include "main.h"

/**
 * _puts - Prints a string to stdout followed by a newline
 * @s: String to print
 */
void _puts(char *s)
{
	while (*s != '\0')
    {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}
