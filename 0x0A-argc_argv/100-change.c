#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on Success; 1 on Error
 */
int main(int argc, char **argv)
{
	int coins = 0;
	int cents;
	int i;
	int coin_types[] = {25, 10, 5, 2, 1};
	char *arg;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	arg = argv[1];
	while (*arg != '\0')
	{
		if (!isdigit(*arg))
		{
			puts("Error");
			return (1);
		}
		arg++;
	}
	cents = atoi(argv[1]);

	for (i = 0; i < 5; i++)
	{
		coins += cents / coin_types[i];
		cents %= coin_types[i];
	}
	printf("%d\n", coins);

	return (0);
}
