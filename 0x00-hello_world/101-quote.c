#include <stdio.h>
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *text = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	fwrite(text, strlen(text), 1, stderr);
	return (1);
}
