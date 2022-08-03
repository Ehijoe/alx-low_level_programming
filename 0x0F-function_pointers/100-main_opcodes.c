#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on Success. 1 if argc is incorrect.
 *         2 if second argument is negative.
 */
int main(int argc, char **argv)
{
	unsigned char *main_char;
	int (*main_func)(int, char **);
	int bytes, i;

	if (argc != 2)
	{
		puts("Error");
		exit(1);
	}
	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		puts("Error");
		exit(2);
	}
	main_func = &main;
	main_char = (char *) main_func;

	for (i = 0; i < bytes; i++)
	{
		printf("%02x", main_char[i]);
		if (i == bytes - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}

	return (0);
}
