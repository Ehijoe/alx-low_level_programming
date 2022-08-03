#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_op_func - Gets the function to call for a particular operator
 * @s: The operator
 *
 * Return: A pointer to the appropriate function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	char *operators = "+-*/%";
	char *found_op;

	found_op = strstr(operators, s);
	if (found_op == NULL)
	{
		puts("Error");
		exit(99);
	}
	return (ops[found_op - operators].f);
}
