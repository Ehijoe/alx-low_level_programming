#include "main.h"
#include <stdlib.h>
#include <limits.h>

#define BASE 1000
#define BASE_DIGS 3

/**
 * carry_over - Carry over excess to make a longnum valid
 * @a: longnum to correct
 */
void carry_over(longnum a)
{
	unsigned int i;

	for (i = a.size - 1; i >= 1; i--)
	{
		a.num[i - 1] += a.num[i] / BASE;
		a.num[i] %= BASE;
	}
}

/**
 * mulnum - Multiply two longnums
 * @a: First longnum
 * @b: Second longnum
 *
 * Return: A longnum whose value is a * b
 */
longnum mulnum(longnum a, longnum b)
{
	longnum ans;
	unsigned int i, j;

	ans.len = a.len + b.len + 2 * BASE_DIGS;
	ans.size = (ans.len / BASE_DIGS) + 1;
	ans.num = malloc(sizeof(unsigned int) * ans.size);
	if (ans.num == NULL)
	{
		print("Error: Could not allocate memory!\n");
		exit(1);
	}
	for (i = 0; i < ans.size; i++)
	{
		ans.num[i] = 0;
	}

	for (i = 0; i < b.size; i++)
	{
		for (j = 0; j < a.size; j++)
		{
			unsigned int mul = a.num[a.size - j - 1] * b.num[b.size - i - 1];

			ans.num[ans.size - i - j - 1] += mul % BASE;
			ans.num[ans.size - i - j - 2] += mul / BASE;
			carry_over(ans);
		}
	}

	return (ans);
}

/**
 * modulo - Replacement of the % operator
 * @a: Dividend
 * @b: Divisor
 *
 * Return: Remainder
 */
unsigned int modulo(unsigned int a, unsigned int b)
{
	return (a - (b * (a / b)));
}

/**
 * printnum - Print a long_num to stdout
 * @n: long_num to print
 */
void printnum(longnum n)
{
	unsigned int i;
	int started = 0;

	if (n.num[0] != 0)
	{
		started = 1;
		print_uint(n.num[0], n.len % BASE_DIGS);
	}
	for (i = BASE_DIGS + (n.len % BASE_DIGS); i <= n.len; i += BASE_DIGS)
	{
		if (!started && n.num[i / BASE_DIGS] == 0)
		{
			continue;
		}
		else if (!started)
		{
			started = 1;
			print_start(n.num[i / BASE_DIGS]);
		}
		else
		{
			print_uint(n.num[i / BASE_DIGS], BASE_DIGS);
		}
	}
}

/**
 * print_start - Print a number without leading zeroes
 * @a: The number to print
 */
void print_start(unsigned int a)
{
	if (a < 10)
	{
		_putchar('0' + a);
	}
	else
	{
		print_start(a / 10);
		_putchar('0' + a % 10);
	}
}

/**
 * readnum - Reads an abitrarily long positive number
 * @s: Number string to read
 *
 * Return: A pointer an array representing the number
 */
longnum readnum(char *s)
{
	unsigned int i;
	longnum result;

	result.len = _strlen(s);
	result.size = (result.len / BASE_DIGS) + 1;
	result.num = malloc(sizeof(unsigned int) * result.size);
	if (result.num == NULL)
	{
		print("Error: Could not allocate memory!\n");
		exit(1);
	}
	i = result.len % BASE_DIGS;
	result.num[0] = unsigned_atoi(s, i);
	for (i += BASE_DIGS; i <= result.len; i += BASE_DIGS)
	{
		result.num[i / BASE_DIGS] = unsigned_atoi(s + i - BASE_DIGS, BASE_DIGS);
	}

	return (result);
}

/**
 * _strlen - Computes the lenght of a null-terminated string
 * @s: String whose characters to count
 *
 * Return: The number of chars in s. 0 if s is NULL.
 */
unsigned int _strlen(char *s)
{
	unsigned int len;

	if (s == NULL)
	{
		return (0);
	}
	for (len = 0; s[len] != '\0'; len++)
	{
		continue;
	}
	return (len);
}

/**
 * print_uint - Print an unsigned integer x with n digits
 * @x: Unsigned integer to print
 * @n: Number of digits in x
 */
void print_uint(unsigned int x, unsigned int n)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		print_uint(x / 10, n - 1);
		_putchar('0' + (x % 10));
	}
}

/**
 * _isdigit - Checks if a character is a digit
 * @c: Character to check
 *
 * Return: 1 if c is a digit, and 0 otherwise
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * unsigned_atoi - Converts n chars of the string num into a number
 * @num: The string to convert to an int
 * @n: Number of digits to read
 *
 * Return: The integer value of the first n digits num
 *         Exits with status 98 if a non-digit is found
 */
unsigned int unsigned_atoi(char *num, unsigned int n)
{
	unsigned int res, i;

	res = 0;
	for (i = 0; i < n; i++)
	{
		if (!_isdigit(num[i]))
		{
			print("Error\n");
			exit(98);
		}
		res = (10 * res) + (num[i] - '0');
	}

	return (res);
}

/**
 * print - Print a null terminated string to stdout
 * @str: String to print
 */
void print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 98 on Error
 */
int main(int argc, char **argv)
{
	longnum a, b, c;

	if (argc != 3)
	{
		print("Error\n");
		return (98);
	}

	a = readnum(argv[1]);
	b = readnum(argv[2]);
	c = mulnum(a, b);
	printnum(c);
	_putchar('\n');

	free(a.num);
	free(b.num);
	free(c.num);

	return (0);
}
