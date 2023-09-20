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

/**
 * operatorcheck - Checks if multiple commands are separated by operators.
 * @line: The input line to check for operators.
 * @count: line count.
 * @env: environment variable.
 * Return: 0 if operators found and handled, -1 otherwise.
 */

int operatorcheck(char *line, int count, char **env)
{
	int i = 0, check = -1;

	while (line[i] != '\0')
	{
		if (line[i] == ';' && line[i + 1] != ';')
			check = 1;
		if (line[i] == '&' && line[i + 1] != '&')
			check = 2;
		if (line[i] == '|' && line[i + 1] != '|')
			check = 3;
		if (line[i] == '$')
			check = 4;
		i++;
	}
	if (check == 1)
	{
		handle_operator(line, count, env, ";");
		return (0);
	}
	if (check == 2)
	{
		handle_operator(line, count, env, "&&");
		return (0);
	}
	if (check == 3)
	{
		handle_operator(line, count, env, "||");
		return (0);
	}
	if (check == 4)
	{
		handle_dollar(line, count, env);
		return (0);
	}
	return (-1);
}

/**
 * handle_operator - Handles multiple commands separated by operators.
 * @line: The input line containing multiple commands.
 * @count: line count.
 * @env : environment variable.
 * @delim: delimiter characters.
 * Return: Always returns 0.
 */

int handle_operator(char *line, int count, char **env, char *delim)
{
	int i = 0;
	int num = 0;
	char **split = NULL;
	char **commands = NULL;

	split = com_arr(line, delim);
	num = command_count(split);
	for (; i < num; i++)
	{
		commands = com_arr(split[i], " \n\t\r");
		handle_path(commands, count, env);
		free_arr(commands);
		if (errno != 0 && (strcmp(delim, "&&") == 0))
			break;
		if (errno == 0 && (strcmp(delim, "||") == 0))
			break;
	}
	free_arr(split);
	return (0);
}

/**
 * handle_dollar - Handle environment variable substitution.
 * @line: The input command line.
 * @count: The line count.
 * @env: The environment variables.
 *
 * Return: 1 if successful, 0 otherwise.
 */

int handle_dollar(char *line, int count, char **env)
{
	int i = 0;
	size_t j = 0, x = 0;
	char *number = NULL;
	pid_t pid = getpid();
	char **commands = NULL;
	int checkdollar = -1;

	commands = com_arr(line, " \n\t\r");
	while (commands[i] != NULL)
	{
		while (x < strlen(commands[i]))
		{
			if (commands[i][x] == '$')
				checkdollar = 1;
			x++;
		}
		if (checkdollar == 1)
		{
			while (j < strlen(commands[i]))
			{
				if (commands[i][j] == '$' && commands[i][j + 1] == '$')
				{
					number = print_number((int)pid);
					free(commands[i]);
					commands[i] = number;
					j++;
				}
				else if (commands[i][j] == '$' && commands[i][j + 1] == '?')
				{
					number = print_number(errno);
					free(commands[i]);
					commands[i] = number;
					errno = 0;
					j++; }
				j++; } }
		i++; }
	handle_path(commands, count, env);
	free_arr(commands);
	return (0);
}
