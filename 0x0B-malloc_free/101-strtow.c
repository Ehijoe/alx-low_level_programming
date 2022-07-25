#include "main.h"
#include <stdlib.h>

/**
 * _isspace - Checks if a character is whitespace or '\0'
 * @c: Character to check
 *
 * Return: 1 if whitespace 0 otherwise
 */
int _isspace(char c)
{
	int i;
	char whitespaces[] = " \t\n\v\f\r";

	for (i = 0; i < 7; i++)
	{
		if (c == whitespaces[i])
		{
			return (1);
		}
	}

	return (0);
}

/**
 * count_words - Count the number of words in a string
 * @str: The string in question
 *
 * Return: The number of words in str
 */
int count_words(char *str)
{
	int words, in_word, i;

	in_word = words = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!_isspace(str[i]))
		{
			if (!in_word)
			{
				words++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		}
	}

	return (words);
}

/**
 * strtow - Converts a string to an array of words
 * @str: The string to split
 *
 * Return: A pointer to the array of words
 */
char **strtow(char *str)
{
	int i, j, word_count;
	char **words;

	if (str == NULL)
		return (NULL);
	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);
	words = malloc((sizeof(char *) * word_count) + 1);
	if (words == NULL)
		return (NULL);
	j = 0;
	for (i = 0; i < word_count; i++)
	{
		int wordlen, k;

		while (_isspace(str[j]))
			j++;
		for (wordlen = 0; !(_isspace(str[wordlen + j])); wordlen++)
			continue;
		words[i] = malloc(wordlen + 1);
		if (words[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(words[k]);
			free(words);
		}
		for (k = 0; k < wordlen; k++)
		{
			words[i][k] = str[j++];
		}
		words[i][wordlen] = '\0';
	}
	words[i] = NULL;
	return (words);
}
