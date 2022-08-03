#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - Add two numbers
 * @a: First Number
 * @b: Second Number
 *
 * Return: a + b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtract two numbers
 * @a: First Number
 * @b: Second Number
 *
 * Return: a - b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiply two numbers
 * @a: First Number
 * @b: Second Number
 *
 * Return: a * b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divide two numbers
 * @a: First Number
 * @b: Second Number
 *
 * Return: a / b
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		puts("Error");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - Find the remainder of division of two numbers
 * @a: First Number
 * @b: Second Number
 *
 * Return: a % b
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		puts("Error");
		exit(100);
	}
	return (a % b);
}
