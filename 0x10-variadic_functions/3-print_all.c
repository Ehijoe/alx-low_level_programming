#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Print arguments according to a format string
 * @format: The format string which shows order of args
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *s;

	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%c", va_arg(args, int));
			break;
		case 'i':
			printf("%d", va_arg(args, int));
			break;
		case 'f':
			printf("%f", va_arg(args, double));
			break;
		case 's':
			s = va_arg(args, char *);
			if (s == NULL)
			{
				printf("(nil)");
				break;
			}
			printf("%s", s);
			break;
		default:
			i++;
			continue;
		}
		i++;
		if (format[i] != '\0')
			printf(", ");
	}
	va_end(args);
	printf("\n");
}
