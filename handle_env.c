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
