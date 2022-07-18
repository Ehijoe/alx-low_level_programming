#include "main.h"

/**
 * set_string - Sets the value of a pointer to a string
 * @s: Pointer to set
 * @to: String to point to
 */
void set_string(char **s, char *to)
{
	*s = to;
}
