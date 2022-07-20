#include "main.h"

/**
 * string_end - Find the end of a string
 * @s: String to find the end of
 *
 * Return: A pointer to the end of the string
 */
char *string_end(char *s)
{
	if (*s == '\0')
	{
		return (s);
	}
	else
	{
		return (string_end(s + 1));
	}
}

/**
 * check_palindrome - Checks if a string of characters is a palindrome
 * @start: Pointer to start of string
 * @end: Pointer to end of string
 *
 * Return: 1 if it is a palindrome and 0 otherwise
 */
int check_palindrome(char *start, char *end)
{
	if ((end - start) < 1)
	{
		return (1);
	}
	else
	{
		return (check_palindrome(start + 1, end - 1) && (*start == *end));
	}
}

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: String to check
 *
 * Return: 1 if s is a palindrome and 0 otherwise.
 */
int is_palindrome(char *s)
{
	return (check_palindrome(s, string_end(s) - 1));
}
