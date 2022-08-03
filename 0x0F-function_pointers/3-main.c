#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on Success. 98 on Error.
 */
int main(int argc, char **argv)
{
	int a, b, c;
	op_func_t f;

	if (argc != 4)
	{
		puts("Error");
		return (98);
	}
	if (get_op_func(argv[2]) == NULL)
	{
		puts("Error");
		return (98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	c = (get_op_func(argv[2]))(a, b);
	printf("%d\n", c);
	return (0);
}
