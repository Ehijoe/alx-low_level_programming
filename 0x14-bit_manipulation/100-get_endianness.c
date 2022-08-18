#include "main.h"

/**
 * get_endianness - Check wether the cpu is little endian of big endian
 *
 * Return: 1 if little endian and 0 if big endian
 */
int get_endianness(void)
{
	int test_int = 1;
	char *first_byte = (char *)&test_int;

	return (*first_byte);
}
