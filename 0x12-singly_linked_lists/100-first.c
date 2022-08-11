#include <stdio.h>
#include <stdlib.h>

/**
 * start - A function to be called before main
 */
void __attribute__ ((constructor)) start(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
