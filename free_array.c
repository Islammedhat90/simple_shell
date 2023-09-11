#include "shell.h"

/**
  * free_arr - function that free double pointer array
  *@arr: array to free.
  * Return: 0 if successful.
  */

int free_arr(char **arr)
{
	int i = 0;

	if (arr != NULL)
	{
		for (; arr[i] != NULL; i++)
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		free(arr);
	}
	else
		perror("trying to free NULL array");
	return (0);
}
