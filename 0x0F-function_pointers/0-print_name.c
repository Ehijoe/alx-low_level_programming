#include "function_pointers.h"

/**
 * print_name - Prints a name with the appropriate function
 * @name: The name to print
 * @f: The function to use to print name
 */
void print_name(char *name, void (*f)(char *))
{
	if (f == NULL)
	{
		return;
	}
	f(name);
}
