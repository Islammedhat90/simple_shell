#include "shell.h"

/**
 * _getenv - function to get value of var from environment table
 * @var: variable to match value for.
 * Return: pointer to value of variable or NULL otherwise.
*/

char *_getenv(char *var)
{
	char **env = environ;
	int size = strlen(var);

	while(*env != NULL)
	{
		if (strncmp(var, *env, size) == 0 && (*env)[size] == '=')
			return (&(*env)[size + 1]);
		env++;
	}
	return (NULL);
}


/**
 * _setenv - function that sets value for an environ
 * @var: variable to either set or create
 * @value: value of variable to be set.
 * Return: 0 if success.
 */

int _setenv(char *var, char *value, char **env)
{
		char *new = NULL;
		int flag = -1;
		size_t len = 0;

		if (var == NULL || value == NULL)
				return (-1);
		len = strlen(var);
		new = malloc(len + strlen(value) + 2);
		if (new == NULL)
		{
				perror("couldn't allocate memory");
				return (-1);
		}
		strcat(new, var);
		strcat(new, "=");
		strcat(new, value);
		while(*env != NULL)
		{
				if (strncmp(var, *env, len) == 0)
				{
						*env = new;
						flag = 1;
				}
				env++;
		}
		if (flag != 1)
		{
			*env = new;
			*env++ = NULL;
		}
		return (0);
}


/**
 * my_setenv - Sets an environment variable to a new value.
 * @commands: An array containing the command and arguments.
 *
 * This function sets an environment variable to a new value.
 *
 * Return: 0 on success, -1 on failure.
 */

int my_setenv(char **commands, char **env)
{
		int count, i = -1;

		count = command_count(commands);
		if (count != 3)
		{
				perror("wrong arguments");
				return (-1);
		}
		i = _setenv(commands[1], commands[2], env);
		if (i == 0)
				return (0);
		else
		{
				perror("Couldn't setenv variable");
				return (-1);
		}
}


