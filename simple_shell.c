#include "shell.h"


/**
  * main - simple_shell initialization.
  *@ac: argument counter.
  *@av: array of arguments.
  *@env: environment variable.
  * Return: 0 if shell exits;
  */

int main(__attribute__((unused))int ac,
__attribute__((unused))char **av, char **env)
{
	char *line = NULL, **commands = NULL, *handledline = NULL;
	char *prompt = "(MY_SHELL) : ";
	size_t n;
	ssize_t read;
	int count = 0, b = 0;
	int mode = isatty(0);

	while (1)
	{
		if (count == 0)
			errno = 0;
		count++;
		if (mode == 1)
			write(1, prompt, strlen(prompt));
		read = getline(&line, &n, stdin);
		if (read == -1)
		{
			if (mode == 1)
				write(1, "\n", 1);
			free(line);
			exit(errno); }
		if (line[0] == '\n' || (line_checker(line) == -1))
			continue;
		handledline = handle_line(line);
		if (operatorcheck(handledline, count, env) != 0)
		{
			commands = com_arr(handledline, " \n\t\r");
			if (commands != NULL)
			{
				b = builtin_checker(commands[0]);
				if (b == -1)
					handle_path(commands, count, env);
				else
					handle_builtin(b, commands, count, handledline, env);
				free_arr(commands); } } }
	free(handledline);
	exit(errno);
	return (0);
}

