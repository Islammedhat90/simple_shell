#include "shell.h"


/**
  * builtin_checker - function that checks if the command is built in.
  *@command: command to be checked.
  * Return: returns number if built in, -1 otherwise
  */

int builtin_checker(char *command)
{
	int i = 0;
	char *builtin[] = {"exit", "env", "setenv", "unsetenv", "cd"};

	if (command != NULL)
	{
		for (; i < 5; i++)
		{
			if (strcmp(command, builtin[i]) == 0)
				return (i);
		}
		return (-1);
	}
	perror("NULL command");
	return (-1);
}

/**
 * handle_builtin - Handles built-in commands based on input code.
 * @m: The code representing the built-in command.
 * @commands: array of commands
 * @count: line count.
 * @handledline: readline from stdin.
 * @env: environment variable.
 * Return: 0 if successful, -1 on error or unknown command.
 */

int handle_builtin(int m, char **commands, int count,
char *handledline, char **env)
{
	if (m == -1)
		return (-1);
	switch (m)
	{
		case 0:
			my_exit(commands, count, handledline);
			return (0);
		case 1:
			my_env(env);
			return (1);
		case 2:
			my_setenv(commands, env);
			return (2);
		case 3:
			_unsetenv(commands, env);
			return (3);
		case 4:
			my_cd(commands);
			return (4);
		default:
			return (-1);
	}
}
