#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on Success; 1 on failure
 */
int main(int argc, char **argv)
{
	int i, sum = 0;

	for (i = 1; i < argc; i++)
	{
		char *num = argv[i];
		int valid = 1;

		while (*num != '\0')
		{
			if (*num < '0' || *num > '9')
			{
				valid = 0;
				break;
			}
			num++;
		}

		if (valid)
		{
			sum += atoi(argv[i]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", sum);
	return (0);
}
