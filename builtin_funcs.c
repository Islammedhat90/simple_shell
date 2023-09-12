#include "shell.h"

/**
  * my_exit - function that implements builtin exit.
  * @void: holds the exit status to print.
  * Return: nothing.
  */

void my_exit(char **commands, int count)
{
        int status;

        if (commands[1] != NULL)
        {
            if (_isdigit(commands[1]) == 0)
            {
                status = _atoi(commands[1]);
                free_arr(commands);
                exit(status);
            }
            else
            {
                print_error(commands[1], count);
                errno = 2;
            }
        }
        status = errno;
        free_arr(commands);
        exit(status);
}

/**
  * my_env - function that prints current environment
  *
  * Return: nothing.
  */

void my_env(void)
{
        char **env = environ;
        int i = 0;

        for (; env[i] != NULL; i++)
        {
            write(1, env[i], strlen(env[i]));
            write(1, "\n", 1);
        }
}
