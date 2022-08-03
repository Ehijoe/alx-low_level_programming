#ifndef CALC_H
#define CALC_H

/**
 * op_func_t - A typedef for the operator functions
 */
typedef int op_func_t(int, int);

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

op_func_t op_add;
op_func_t op_sub;
op_func_t op_mul;
op_func_t op_div;
op_func_t op_mod;

op_func_t *get_op_func(char *s);

#endif
