#include "shell.h"

/**
  * my_exit - function that implements builtin exit.
  * @void: holds the exit status to print.
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
  *
  * Return: nothing.
  */

void my_env(char **env)
{
      int i = 0, j = 0;

      while (env[i])
      {
        while (env[i][j])
        {
          write(1, &env[i][j], 1);
          j++;
        }
        j = 0;
        i++;
        write(1, "\n", 1);
      }
}
