#include "main.h"

/**
 * wildcmp_helper - Compares two strings accounting for wildcards
 * @s1: First string to compare
 * @s2: Second string which may contain wildcards
 * @wildcard: 1 if a wildcard has been encountered 0 otherwise
 *
 * Return: 1 if the string match, 0 otherwise
 */
int wildcmp_helper(char *s1, char *s2, int wildcard)
{
	if (wildcard)
	{
		if (*s1 == *s2)
		{
			if (wildcmp_helper(s1, s2, 0))
				return (1);
			return (wildcmp_helper((s1 + 1), s2, 1));
		}
		if (*s1 == '\0')
			return (0);
		return (wildcmp_helper((s1 + 1), s2, 1));
	}
	else
	{
		if (*s2 == '*')
		{
			if (s2[1] == '*')
				return (wildcmp_helper(s1, (s2 + 1), 0));
			return (wildcmp_helper(s1, (s2 + 1), 1));
		}
		else if (*s1 == *s2)
		{
			if (*s1 == '\0')
				return (1);
			else
				return (wildcmp_helper((s1 + 1), (s2 + 1), 0));
		}
		else /* s1 != s2 */
			return (0);
	}
}

/**
 * wildcmp - Check if two strings match
 * @s1: First string to check
 * @s2: Second string which may contain wildcards
 *
 * Return: 1 if the strings match, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_helper(s1, s2, 0));
}
