#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * f5 - Get the offset for the fifth character
 * @username: The username to guess the password for
 * @len: Length of the username
 *
 * Return: The offset of the 5th character
 */
int f5(char *username, int len)
{
	int i, offset = 0;

	for (i = 0; i < len; i++)
		offset += username[i] * username[i];
	return (((offset & 0xff) ^ 0xef) & 0x3f);
}


/**
 * f6 - Get the offset for the 6th character
 * @first: First character of the username
 *
 * Return: The offset for the first character
 */
int f6(char first)
{
	int i;
	int offset = 0;

	for (i = 0; i < first; i++)
		offset = rand();
	return ((offset ^ 0xe5) & 0x3f);
}


/**
 * main - entry point
 * @argc: The number of arguments
 * @argv: The list of arguments
 *
 * Return: 0 on success. 1 on failure.
 */
int main(int argc, char **argv)
{
	char password[7];
	char *username, max;
	char *allowed =
"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	int i, len, offset;

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}
	password[6] = '\0';
	username = argv[1];
	len = strlen(username);
	offset = (len ^ 0x3b) & 0x3f;
	password[0] = allowed[offset];
	offset = 0;
	for (i = 0; i < len; i++)
		offset += username[i];
	offset = (offset ^ 0x4f) & 0x3f;
	password[1] = allowed[offset];
	offset = 1;
	for (i = 0; i < len; i++)
		offset *= username[i];
	offset = (offset ^ 0x55) & 0x3f;
	password[2] = allowed[offset];
	for (i = 0, max = username[0]; i < len; i++)
		max = (max > username[i]) ? max : username[i];
	srand(max ^ 0xe);
	password[3] = allowed[rand() & 0x3f];
	password[4] = allowed[f5(username, len)];
	password[5] = allowed[f6(username[0])];
	printf("%s", password);
	return (0);
}
