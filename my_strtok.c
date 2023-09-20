#include "shell.h"


/**
 * delimcheck - Checks if a character is present in a delimiter string.
 * @c: The character to check.
 * @delim: The delimiter string to compare against.
 * Return: 1 if @c is a delimiter, 0 otherwise.
 */

int delimcheck(char c, const char *delim)
{
	size_t i = 0;
	size_t len;

	len = strlen(delim);
	for (; i < len; i++)
	{
		if (c == delim[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - Tokenize a string.
 * @line: The string to tokenize.
 * @delim: The delimiter characters.
 * Return: A pointer to the next token found in the string, or NULL if no
 *         more tokens are found.
 */

char *_strtok(char *line, const char *delim)
{
	size_t i = 0;
	static char *pointer;
	char *token = NULL;

	if (line != NULL)
		pointer = line;
	if (delim == NULL || pointer == NULL)
		return (NULL);
	if (delim != NULL)
	{
		if (delimcheck(pointer[i], delim))
		{
			while (delimcheck(pointer[i], delim))
				i++;
			if (pointer[i] != '\0')
			{
				pointer = &pointer[i];
				i = 0;
			}
		}
		for (; pointer[i] != '\0'; i++)
		{
			if (delimcheck(pointer[i], delim))
			{
				pointer[i] = '\0';
				token = pointer;
				pointer = &pointer[i + 1];
				return (token);
			}
		}
		if (pointer[i] == '\0')
		{
			token = pointer;
			pointer = NULL;
			return (token);
		}
	}
	return (NULL);
}
