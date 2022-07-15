#include "main.h"

/**
 * is_word_sep - Checks if a character is a valid word seperator
 * @c: Character to check
 *
 * Return: 1 if it is and 0 otherwise
 */
int is_word_sep(char c)
{
	switch (c)
	{
	case ',':
	case ' ':
	case '\t':
	case '\n':
	case ';':
	case '.':
	case '!':
	case '?':
	case '"':
	case '(':
	case ')':
	case '{':
	case '}':
		return (1);
	default:
		return (0);
	}
}

/**
 * cap_string - Capitalize every word in a string
 * @s: String to capitalize
 *
 * Return: A pointer to s
 */
char *cap_string(char *s)
{
	int word_start = 1, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_word_sep(s[i]))
		{
			word_start = 1;
			continue;
		}

		if (word_start)
		{
			word_start = 0;
			if (s[i] <= 'z' && s[i] >= 'a')
			{
				s[i] += 'A' - 'a';
			}
		}
	}

	return (s);
}
