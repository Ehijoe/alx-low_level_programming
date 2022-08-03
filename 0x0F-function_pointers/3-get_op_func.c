#include "3-calc.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_op_func - Gets the function to call for a particular operator
 * @s: The operator
 *
 * Return: A pointer to the appropriate function
 */
op_func_t *get_op_func(char *s)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].op != NULL && s != NULL; i++)
	{
		if (strcmp(ops[i].op, s) == 0)
		{
			return (ops[i].f);
		}
	}
	return (NULL);
}
