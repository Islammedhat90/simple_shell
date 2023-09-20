#include "shell.h"

/**
  * my_exit - function that implements builtin exit.
  * @commands: array of commands or arguments.
  * @count: line count.
  * @handledline: read line fro stdin.
  * Return: nothing.
  */

void my_exit(char **commands, int count, char *handledline)
{
	int status;

	if (commands[1] != NULL)
	{
		if (_isdigit(commands[1]) == 0)
		{
			status = _atoi(commands[1]);
			free_arr(commands);
			free(handledline);
			exit(status);
		}
		else
		{
			print_error(commands[1], count);
			errno = 2;
		}
	}
	status = errno;
	free(handledline);
	free_arr(commands);
	exit(status);
}

/**
  * my_env - function that prints current environment
  * @env: environment variable.
  * Return: nothing.
  */

void my_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(1, env[i], strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
}

/**
 * my_cd - Change the current working directory.
 * @commands: An array of strings containing the command and arguments.
 * @env: environment variable.
 * @count: line count.
 * Return: 0 if success, -1 otherwise.
 */

int my_cd(char **commands, __attribute__((unused))char **env, int count)
{
	int check = -1;
	int counts = command_count(commands);
	char *dir = NULL;

	if (counts > 2)
	{
		perror("./hsh: cd: too many arguments");
	}
	if (counts == 1)
	{
		dir = _getenv("HOME");
	}
	else if (commands[1][0] == '-')
	{
		dir = _getenv("OLDPWD");
	}
	else
	{
		dir = strdup(commands[1]);
		check = 1;
	}
	if (chdir(dir) == 0)
	{
		if (check == 1)
		{
			free(dir);
			check = -1;
		}
		return (0);
	}
	print_cderror(commands[1], count);
	if (check == 1)
		free(dir);
	return (-1);
}

