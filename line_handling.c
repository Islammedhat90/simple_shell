#include "shell.h"
/**
 * handle_line - Function handles the line that user enters
 * @line: Take the line from getline function
 * Return: The handled string without new line
*/
char *handle_line(char *line)
{
	size_t len;
	int i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			line += i;
			break;
		}
		i++;
	}
	len = strlen(line);
	if (len == 1 && line[0] == '\n')
		return (line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
/**
 * line_checker - Checks if a line contains non-whitespace characters.
 * @line: The input line to check.
 *
 * Return: 1 if the line contains non-whitespace characters, -1 if it's empty.
 */

int line_checker(char *line)
{
	int i = 0;

	if (line != NULL)
	{
		for (; line[i] != '\0'; i++)
		{
			if (line[i] != ' ' && line[i] != '\n')
				return (1);
		}
	}
	return (-1);
}

