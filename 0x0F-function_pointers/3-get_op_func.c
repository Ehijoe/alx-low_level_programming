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

	if (strstr(operators, s) == NULL)
	{
		return (NULL);
	}
	return (ops[strstr(operators, s) - operators].f);
}
